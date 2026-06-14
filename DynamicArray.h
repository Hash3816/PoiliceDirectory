#pragma once
#include "IStorage.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

template<typename Info>
class DynamicArray : public InterfaceStorage<Info> {
private:
	Info* array;
	unsigned int capacity;
	unsigned int size;
    static const unsigned int max_capacity = 20000;

	void expand() {
		capacity *= 2;
        if (capacity > max_capacity) {
			throw std::runtime_error("array overflow");
        }

		Info* new_array = new Info[capacity];
		for (int i = 0; i < size; i++) {
			new_array[i] = array[i];
		}
		delete[]array;
		array = new_array;
	}

	void reduce(){
		capacity /= 2;
		
		Info* new_array = new Info[capacity];
		for (int i = 0; i < size; i++) {
			new_array[i] = array[i];
		}

		delete[] array;
		array = new_array;
	}

public:
	DynamicArray() {
		size = 0;
		capacity = 2;
		array = new Info[capacity];
	}

	DynamicArray(int n) {
        if (n < 0 || n >= max_capacity) {
			throw std::runtime_error("invalid size array");
		}
		size = 0;
		capacity = n;
		array = new Info[capacity];
	}

	~DynamicArray() {
		delete[] array;
	}

	void push_back(const Info& info) override{
		if (size == capacity) {
			expand();
		}

		size++;
		array[size - 1] = info;
	}

	void pop_back() override{
		if (size == 0) {
			throw std::runtime_error("no elements in array");
		}

		size--;
		if (size < capacity / 2) {
			reduce();
		}
	}

	void insert(const Info& info, int index) override{
		if (index < 0 || index >= size) {
			throw std::runtime_error("index out of range");
		}

		if (size == capacity) {
			expand();
		}

		for (int i = size; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = info;
		size++;
	}

	void erase(int index) override{
		if (index < 0 || index >= size) {
			throw std::runtime_error("index out of range");
		};

		for (int i = index; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
		pop_back();
	}

	void change(const Info& info, int index) override {
		if (index < 0 || index >= size) {
			throw std::runtime_error("index out of range");
		}
		array[index] = info;
	}

    const Info& get_element(int index)const override{
        if(index < 0 || index >= size){
            throw std::runtime_error("index out of range");
        }
        return array[index];
    }

	std::string to_str() const  override {
		std::stringstream str_stream;
		for (int i = 0; i < size; i++) {
			str_stream << array[i] << "\n";
		}
		return str_stream.str();
	}

	void print() const override {
		std::cout << to_str();
	}

    const unsigned int get_size() const override{
		return size;
	}

    unsigned int get_capacity() const{
		return capacity;
	}

    bool empty() const override{
		return size == 0;
	}

	void clear() override {
        delete[] array;
        array = new Info[2];
		size = 0;
		capacity = 2;
	}
};