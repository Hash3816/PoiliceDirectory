#pragma once
#include "../Pair.h"
#include "string"

template<typename Info, typename Key, typename Value>
class IHashTableManager {
public:
    virtual ~IHashTableManager() = default;

    virtual void append(const Info& info) = 0;
    virtual void erase(const Info& info, const Value& ind) = 0;
    virtual Pair<unsigned int, const Info&> find(const Key& key) const = 0;
	virtual void load_data_from_file(const std::string& path) = 0;
	virtual void write_index_structure_in_file(const std::string& path) const = 0;
	virtual void write_storage_in_file(const std::string& path) const = 0;
	virtual void print_data_structure_index() const  = 0;
	virtual void print_storage() const = 0;
    virtual unsigned int get_hash(const Key& key) const = 0;
	virtual void clear() = 0;
};
