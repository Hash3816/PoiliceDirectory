#pragma once
#include "IStorage.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

template<typename Info>
class StaticArray : public InterfaceStorage<Info> {
private:
    Info array[9999];
    static const unsigned int max_capacity = 9999;
	unsigned int size;


public:
    StaticArray() {
		size = 0;
	}

    ~StaticArray() = default;

	void push_back(const Info& info) override{
        if (size >= max_capacity) {
            throw std::runtime_error("Массив переполнен.");
		}

		size++;
		array[size - 1] = info;
	}

	void pop_back() override{
		if (size == 0) {
            throw std::runtime_error("Элементы в массиве не найдены.");
		}

		size--;
	}

	void insert(const Info& info, int index) override{
		if (index < 0 || index >= size) {
            throw std::runtime_error("Индекс находится за пределами массива.");
		}

        if (size >= max_capacity) {
            throw std::runtime_error("Массив переполнен.");
		}

		for (int i = size; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = info;
		size++;
	}

	void erase(int index) override{
        if ((index < 0) || (index >= size)) {
            throw std::runtime_error("Индекс находится за пределами массива.");
		};

		for (int i = index; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
		pop_back();
	}

	void change(const Info& info, int index) override {
		if (index < 0 || index >= size) {
            throw std::runtime_error("Индекс находится за пределами массива.");
		}
		array[index] = info;
	}

    const Info& get_element(int index)const override{
        if(index < 0 || index >= size){
            throw std::runtime_error("Индекс находится за пределами массива.");
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

    unsigned int get_size() const override{
		return size;
	}

    unsigned int get_capacity() const{
        return max_capacity;
	}

    bool empty() const override{
		return size == 0;
	}

	void clear() override {
		size = 0;
	}
};