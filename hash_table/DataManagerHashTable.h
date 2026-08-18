#pragma once
#include <fstream>
#include "IHashTableManager.h"
#include "IHashTableIndex.h"
#include "../IStorage.h"
#include "../structures.h"


//Key - unsigned int номер заявления в предметной задаче
//Value - unsigned int - индекс в массиве
class DataManagerHashTable :public IHashTableManager<PoliceReport, unsigned int, unsigned int> {
private:
    InterfaceStorage<PoliceReport>* storage_info;
    IHashTableIndex<unsigned int, unsigned int>* hash_table;

public:
    DataManagerHashTable() = delete;

    DataManagerHashTable(InterfaceStorage<PoliceReport>* storage, IHashTableIndex<unsigned int, unsigned int>* table){
        //Передача конкретных реализаций
        storage_info = storage;
        hash_table = table;
    }

    ~DataManagerHashTable(){
        delete storage_info;
        delete hash_table;
    }

    void append(const PoliceReport& info) override{
        if(hash_table->find(info.report_number).first){// Количество шагов поиска, если объекта с ключом нет в хт то выведет 0
            throw std::runtime_error("Невозможно вставить дубликат.");
        }

        storage_info->push_back(info);
        hash_table->insert(info.report_number, storage_info->get_size() - 1);
	}

    void erase(const PoliceReport& info, const unsigned int& index) override {
        if (index < 0 || index > storage_info->get_size() - 1) {
            throw std::runtime_error("Индекс находится за пределами массива.");
		}
        if (storage_info->get_element(index) != info) {
            throw std::runtime_error("Неверный индекс.");
		}

        hash_table->erase(info.report_number, index);
        if (index != storage_info->get_size() - 1) {
            PoliceReport last_info_in_array = storage_info->get_element(storage_info->get_size() - 1);
            storage_info->change(last_info_in_array,index);

            hash_table->erase(last_info_in_array.report_number, storage_info->get_size() - 1);
            hash_table->insert(storage_info->get_element(index).report_number, index);
		}
        storage_info->pop_back();
	}

    Pair<unsigned int, const PoliceReport&> find(const unsigned int& report_number) const override{
        Pair<unsigned int, const unsigned int&> pair_index = hash_table->find(report_number);
        if(pair_index.first == 0){
            static const PoliceReport empty_report = PoliceReport();
            return Pair<unsigned int, const PoliceReport&>(0,  empty_report);
        }
        return Pair<unsigned int, const PoliceReport&>(pair_index.first, storage_info->get_element(pair_index.second));
	}

    //Работает только если действительно по всем заявлениям существуют следствия в файле
	void load_data_from_file(const std::string& path) override {
		std::ifstream input;

		input.open(path);
		if (!input.is_open()) {
            throw std::runtime_error("Ошибка при открытии файла.");
		}
       
		int number_rows;
		input >> number_rows;
        if(input.fail()){
            throw std::runtime_error("Файл повреждён.");
        }
		input.get();
		std::string info_user_s;
		for (int i = 0; i < number_rows; i++) {
			std::getline(input, info_user_s);
            append(string_to_report(info_user_s));
		}
        input.close();
	}

	void write_index_structure_in_file(const std::string& path) const override{
		std::ofstream output(path);
		if (!output.is_open()) {
            throw std::runtime_error("Невозможно открыть(создать) файл.");
		}
        output << hash_table->to_str();
		output.close();
	}

	void write_storage_in_file(const std::string& path)const  override {
		std::ofstream output(path);
		if (!output.is_open()) {
            throw std::runtime_error("Невозможно открыть(создать) файл");
		}
        output << storage_info->get_size() << "\n";
        output << storage_info->to_str();
		output.close();
	}

	void print_data_structure_index() const  override{
        hash_table->print();
	}

    const InterfaceStorage<PoliceReport>& get_storage() const{
        return *storage_info;
    }

    void set_capacity(unsigned int n){
        hash_table->set_capacity(n);
    }

	void print_storage() const  override {
        storage_info->print();
	}

    std::string hash_table_to_string() const{
        return hash_table->to_str();
    }

    std::string storage_to_string() const{
        return storage_info->to_str();
    }

    unsigned int get_hash(const unsigned int& key) const override{
        return hash_table->get_hash(key);
    }

    void clear() override{
        storage_info->clear();
        hash_table->clear();
    }
};