#pragma once
#include <fstream>
#include "I_tree.h"
#include "IDataManagerTree.h"
#include "../IStorage.h"
#include "../structures.h"


class DataManagerTree : public IDataManagerTree<Investigation, unsigned int, unsigned int>{
private:
    InterfaceStorage<Investigation>* storage_info;
    ITree<unsigned int, unsigned int>* tree;
    ITree<Date, unsigned int>* tree_dates;

public:
    DataManagerTree() = delete;

    DataManagerTree(InterfaceStorage<Investigation>* storage, ITree<unsigned int, unsigned int>* tree, ITree<Date, unsigned int>* tree_dates){
        this->storage_info = storage;
        this->tree = tree;
        this->tree_dates = tree_dates;
    }
    ~DataManagerTree(){
        delete storage_info;
        delete tree;
        delete tree_dates;
    }

    void append(const Investigation& info) override{
        storage_info->push_back(info);
        tree->insert(info.report_number, storage_info->get_size() - 1);
        tree_dates->insert(info.initiation_date, storage_info->get_size() - 1);
	}

    void erase(const Investigation& info, const unsigned int& index) override{
        if (index < 0 || index > storage_info->get_size() - 1) {
			throw std::runtime_error("index out of range");
		}
        if (storage_info->get_element(index) != info) {
			throw std::runtime_error("invalid index");
		}

        tree->erase(info.report_number, index);
        tree_dates->erase(info.initiation_date, index);
        if (index != storage_info->get_size() - 1) {
            Investigation last_info_in_array = storage_info->get_element(storage_info->get_size() - 1);
            storage_info->change(last_info_in_array, index); //На место удалённого последний
            //Обновляем индексы у деревьев
            tree->erase(last_info_in_array.report_number, storage_info->get_size() - 1);
            tree_dates->erase(last_info_in_array.initiation_date, storage_info->get_size() - 1);
            tree->insert(storage_info->get_element(index).report_number, index);
            tree_dates->insert(storage_info->get_element(index).initiation_date, index);
		}
        storage_info->pop_back();
	}

    Pair<unsigned int, const List<unsigned int>&> find( const unsigned int& report_number) const override{
        return tree->find(report_number);
	}
    Pair<unsigned int, const List<unsigned int>&> find_date(const Date& initiation_date) const{
        return tree_dates->find(initiation_date);
    }


	void load_data_from_file(const std::string& path) override{
		std::ifstream input;

		input.open(path);
		if (!input.is_open()) {
			throw std::runtime_error("cannot open(create) file");
		}

		int number_rows;
		input >> number_rows;
		input.get();
        if(input.fail()){
            throw std::runtime_error("invalid number rows");
        }
		std::string info_user_s;
		for (int i = 0; i < number_rows; i++) {
			std::getline(input, info_user_s);
			append(string_to_investigation(info_user_s));
		}

        input.close();
	}

	void write_index_structure_in_file(const std::string& path) const override{
		std::ofstream output(path);
		if (!output.is_open()) {
			throw std::runtime_error("cannot open(create) file");
		}

        output << tree->to_str();
		output.close();
	}

	void write_storage_in_file(const std::string& path) const override{
		std::ofstream output(path);
		if (!output.is_open()) {
			throw std::runtime_error("cannot open(create) file");
		}

        output << storage_info->get_size() << "\n";
        output << storage_info->to_str();
		output.close();
	}
    const InterfaceStorage<Investigation>& get_storage() const {
        return *storage_info;
    }

	void print_data_structure_index() const override{
        tree->print();
	}

    void print_storage()const override{
        storage_info->print();
	}

    void print_tree_dates() const{
        tree_dates->print();
    }

    std::string tree_dates_to_string() const{
        return tree_dates->to_str();
    }

    std::string tree_investigations_to_string() const{
        return tree->to_str();
    }

    std::string storage_to_string() const{
        return storage_info->to_str();
    }

    void clear() override{
        tree->clear();
        tree_dates->clear();
        storage_info->clear();
    }
};