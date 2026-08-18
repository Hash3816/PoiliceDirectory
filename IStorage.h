#pragma once
#include <string>

template<typename Info>
class InterfaceStorage {
public:
    virtual ~InterfaceStorage() = default;

	virtual void push_back(const Info& info) = 0;
	virtual void pop_back() = 0;
	virtual void erase(int index) = 0;
	virtual void insert(const Info& info, int index) = 0;
    virtual unsigned int get_size() const  = 0;
    virtual const Info& get_element(int index) const = 0;
	virtual void change(const Info& info, int index) = 0;
    virtual bool empty() const = 0;
	virtual std::string to_str()const = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};