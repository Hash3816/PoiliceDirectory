#pragma once
#include<sstream>
#include<cmath>
#include<iostream>
#include "IHashTableIndex.h"


template<typename Key, typename Value>
class HashTable: public IHashTableIndex<Key, Value> {
private:
	enum class State {
		empty,
        occupied
	};

	struct Node {
		State state;
		Key key;
		Value value;
	};


    Node* dynamic_array;
	unsigned int size;
	unsigned int capacity;

    const float max_occupied_coefficient = 0.75; // не включительно(при достижении этого числа перехещ)
    const float min_occupied_coefficient = 0.25; // при достижении этого коэфициента сужение за исключением случаев когда capcity\2 < 4
    const unsigned int max_capacity = 39800; //включительно 9999/39800.25123...
    const unsigned int min_capacity = 4; //Включительно

	void expand() {
        if (capacity * 2 > max_capacity) {
            throw std::runtime_error("Hash table overflow"); //Очень плохая ошибка она не должна произойти
        }

		int old_capacity = capacity;
		Node* old_array = dynamic_array;

		capacity *= 2;
		dynamic_array = new Node[capacity];
		
		for (int i = 0; i < capacity; i++) {
			dynamic_array[i].state = State::empty;
		}

		size = 0;
		for (int i = 0; i < old_capacity; i++) {
			if (old_array[i].state == State::occupied) {
				insert(old_array[i].key, old_array[i].value);
			}
		};

		delete[] old_array;
	}

	
	void reduce() {
		if (capacity / 2 < min_capacity) {
			return;
		}

		int old_capacity = capacity;
		capacity /= 2;

		Node* old_array = dynamic_array;
		dynamic_array = new Node[capacity];

		for (int i = 0; i < capacity; i++) {
			dynamic_array[i].state = State::empty;
		}

		size = 0;
		for (int i = 0; i < old_capacity; i++) {
			if (old_array[i].state == State::occupied) {
				insert(old_array[i].key, old_array[i].value);
			}
		};

		delete[] old_array;
	}


    // unsigned int hash(std::string& key) const{
    //     std::stringstream s_s_key;
    //     s_s_key << key;
    //     std::string s_key = s_s_key.str();
    //     if (s_key.size() > 99) {
    //         throw std::runtime_error("Invalid length key");
    //     }

    //     double num = 0.0;
    //     double a = 0.618033;
    //     double base = 31;
    //     for (int i = 0; i < s_key.size(); i++) {
    //         num = fmod(num*base + static_cast<unsigned char>(s_key[i]) * a, 1.0);
    //     }
    //     num *= capacity;

    //     return static_cast<unsigned int>(num);
    // }

    unsigned int hash(const Key& key) const {
        std::stringstream s_s_key;
        s_s_key << key;
        std::string s_key = s_s_key.str();
        if ((s_key.size() <= 0) || (s_key.size() > 300)) {
            throw std::runtime_error("Invalid length key");
        }

        double num = 0.0;
        double a = 0.618033;
        for (int i = 0; i < s_key.size(); i++) {
            num += static_cast<unsigned char>(s_key[i]);
        }
        num *= a;
        num = fmod(num, 1.0);
        num *= capacity;

        return static_cast<unsigned int>(num);
    }

    unsigned int secondary_hash(unsigned int primary_hash, unsigned int attempt_number) const{
		return (primary_hash + attempt_number) % capacity;
	}

    float get_occupied_coefficient() const{
		return (static_cast<float>(size) / static_cast<float>(capacity));
	}

public:
	HashTable() {
		dynamic_array = new Node[min_capacity];
		capacity = min_capacity;
		size = 0;
		for (int i = 0; i < min_capacity; i++) {
			dynamic_array[i].state = State::empty;
		}
	};

    HashTable(unsigned int n){
		if (n < min_capacity) {
			throw std::runtime_error("Invalid capacity or capacity too small");
		}

		dynamic_array = new Node[n];
		capacity = n;
		size = 0;
		for (int i = 0; i < n; i++) {
			dynamic_array[i].state = State::empty;
		}
	};

	~HashTable() {
		delete[] dynamic_array;
	};

    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;


    void set_capacity(unsigned int n) override{
        if(n < min_capacity){
            throw std::runtime_error("Invalid capacity. Capacity always >= 4.");
        }
        if(n == capacity){
            throw std::runtime_error("input capacity equal current.");
        }

        unsigned int old_capacity = capacity;
        Node* old_array = dynamic_array;

        capacity = n;
        if(get_occupied_coefficient() >= max_occupied_coefficient || get_occupied_coefficient() <= min_occupied_coefficient){
            capacity = old_capacity;
            throw std::runtime_error("Invalid capacity. Occupied coefficient shoud be 25% < x < 75%\n"
                                     "Where x - Occupied coefficient.");
        }
        if(n > max_capacity){
            capacity = old_capacity;
            std::string error = "Invalid capacity. max_capacity = " + std::to_string(max_capacity);
            throw std::runtime_error(error);
        }
        if(n < size){
            capacity = old_capacity;
            std::string error = "Capcity can`t be less than size. Current size: " + std::to_string(size);
            throw std::runtime_error(error);
        }

        dynamic_array = new Node[capacity];
        for (int i = 0; i < capacity; i++) {
            dynamic_array[i].state = State::empty;
        }

        size = 0;
        for (int i = 0; i < old_capacity; i++) {
            if (old_array[i].state == State::occupied) {
                insert(old_array[i].key, old_array[i].value);
            }
        }

        delete[] old_array;
    }


    void insert(const Key& key, const Value& value) override{
		Node node;
		node.state = State::occupied;
		node.value = value;
		node.key = key;
		
		unsigned int primary_hash = hash(key);
		unsigned int step_number = 1;

		unsigned int index = primary_hash;
		while (dynamic_array[index].state == State::occupied) {
			if (dynamic_array[index].key == key) {
                throw std::runtime_error("Impossible to insert a duplicate");
			}
			index = secondary_hash(primary_hash, step_number);
			step_number++;
		}
		dynamic_array[index] = node;
		size++;

		if ((get_occupied_coefficient() >= max_occupied_coefficient)){ 
			expand();
		}
	}

    void erase(const Key& key, const Value& value_erase) override{

        unsigned int primary_hash = hash(key);
        unsigned int step_number = 1;

        unsigned int index = hash(key);
		while (dynamic_array[index].state == State::occupied) {
			if (key == dynamic_array[index].key) {
				break;
			}

			index = secondary_hash(primary_hash, step_number);
			step_number += 1;
		}

		if (dynamic_array[index].state == State::empty) {
            throw std::runtime_error("Object not found.");
		}

		dynamic_array[index].state = State::empty;
		size--;

        
        step_number = 1;
        unsigned int primary_j = secondary_hash(index, step_number);
        unsigned int j = primary_j;

		while (dynamic_array[j].state == State::occupied) {
			Node node = dynamic_array[j];
			dynamic_array[j].state = State::empty;
			insert(node.key, node.value);

			size--;
			j = secondary_hash(primary_j, step_number);
			step_number += 1;
		}

		if  ((get_occupied_coefficient() <= min_occupied_coefficient)) {
			reduce();
		}
	}

	
    Pair<unsigned int, const Value&> find(const Key& key) const  override{
        unsigned int primary_hash = hash(key);
        unsigned int i = primary_hash;
        unsigned int step_number = 1;
		while (dynamic_array[i].state == State::occupied) {
			if (key == dynamic_array[i].key) {
                return Pair<unsigned int, const Value&>(step_number, dynamic_array[i].value);
			}
			i = secondary_hash(primary_hash, step_number);
			step_number += 1;
		}
        static const Value empty_value = Value();
        return Pair<unsigned int, const Value&>(0, empty_value);
	}

	
    std::string to_str() const  override{
		std::stringstream str_stream;
		for (int i = 0; i < capacity; i++) {
			if (dynamic_array[i].state == State::empty) {
				str_stream << "index:" << i << " " << "<empty>" << "\n";
			}
			else {
				str_stream << "index:" << i << " " << "key: " << dynamic_array[i].key << " value: " << dynamic_array[i].value << "\n";
			}
		}
		return str_stream.str();
	}

    void print() const override {
		std::cout << to_str();
	}

    void clear() override {
		delete[]dynamic_array;
        dynamic_array = new Node[min_capacity];
		size = 0;
		capacity = min_capacity;
	}
};