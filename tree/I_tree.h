#pragma once
#include <string>
#include "../Pair.h"
#include "../list.h"

template<typename Key, typename Value>
class ITree {
public:
	virtual ~ITree() = default;

	virtual void insert(const Key& key, const Value& value) = 0;
	virtual void erase(const Key& key, const Value& value) = 0;
    virtual Pair<unsigned  int, const List<Value>&> find(const Key& key) const = 0;
	virtual void print() const = 0;
	virtual std::string to_str() const = 0;
	virtual void clear() = 0;
};
