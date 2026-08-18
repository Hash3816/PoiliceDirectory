#pragma once
#include <QRegularExpression>
#include <QString>
#include <vector>
#include <fstream>
#include "validate_structures.h"
#include "IStorage.h"
#include "./tree/DataManagerTree.h"
#include "./hash_table/DataManagerHashTable.h"
#include "StaticArray.h"
#include "./hash_table/hash_table.h"
#include "./tree/rb_tree.h"
#include "validate_structures.h"

class DataService{
private:
    DataManagerHashTable reports_directory;
    DataManagerTree investigations_directory;

    DataService() :
        reports_directory(new StaticArray<PoliceReport>, new HashTable<unsigned int, unsigned int>),
        investigations_directory(new StaticArray<Investigation>, new RB_tree<unsigned int, unsigned int>,
            new RB_tree<Date, unsigned int>) {
    }
    ~DataService() = default;

public:
    DataService(const DataService&) = delete;
    DataService& operator=(const DataService&) = delete;
    DataService(DataService&&) = delete;
    DataService& operator=(DataService&&) = delete;

    static DataService& get_instance() {
        static DataService instance;
        return instance;
    }

    const InterfaceStorage<PoliceReport>& load_reports_from_file(const std::string& path){
        reports_directory.load_data_from_file(path);
        return reports_directory.get_storage();
    }
    const InterfaceStorage<Investigation>& load_investigations_from_file(const std::string& path) {
        std::ifstream input;

        input.open(path);
        if (!input.is_open()) {
            throw std::runtime_error("Ошибка при открытии файла.");
        }

        int number_rows;
        input >> number_rows;
        input.get();
        if(input.fail()){
            throw std::runtime_error("Файл повреждён.");
        }
        std::string info_user_s;
        for (int i = 0; i < number_rows; i++) {
            std::getline(input, info_user_s);
            Investigation investigation = string_to_investigation(info_user_s);

            if(reports_directory.find(investigation.report_number).first == 0){
                throw std::runtime_error("В файле обнаружено следствие, номера заявления которого нет в справочнике заявлений.");
            }
            investigations_directory.append(investigation);
        }
        return investigations_directory.get_storage();
    }

    void save_report_directory(const std::string& path) const {
        reports_directory.write_storage_in_file(path);
    };

    void save_investigation_directory_in_file(const std::string& path) const {
        investigations_directory.write_storage_in_file(path);
    };


    void add_report(const PoliceReport& report){
        //Дублирование валидации с дополнительными проверками
        if(reports_directory.get_storage().get_size() > 9999){
            throw std::runtime_error("Невозможно добавить заявление. Справочник переполнен.");
        }

        if(report.report_number < 1 || report.report_number > 9999){
            throw std::runtime_error("Некорректный номер заявления.");
        }
        if(report.description.size() > 200){
            throw std::runtime_error("Поле описание превышает допустимый размер.");
        }

        validate_full_name(report.applicant);
        reports_directory.append(report);
    };
    void del_report(const PoliceReport& report, unsigned int index) {
        reports_directory.erase(report, index);
    }

  
    void add_investigation(const Investigation& investigation) {
        if(investigation.report_number < 1 || investigation.report_number > 9999){
            throw std::runtime_error("Некорректный номер заявления.");
        }
        if (reports_directory.find(investigation.report_number).first == 0) {
            throw std::runtime_error("В справочнике заявлений не найден заданный номер заявления.\n Сначала добавьте заявление в справочник заявлений.");
        }
        validate_full_name(investigation.investigator);
        investigations_directory.append(investigation);
    };
    void del_investigation(const Investigation& investigation, unsigned int index){
            validate_full_name(investigation.investigator);

            investigations_directory.erase(investigation, index);
    };


    Pair<unsigned int, std::vector<std::reference_wrapper<const PoliceReport>>> find_report_data(const unsigned int& report_number) const{
        if(report_number < 1 || report_number > 9999){
            throw std::runtime_error("Некорректный номер заявления.");
        }

        std::vector<std::reference_wrapper<const PoliceReport>> result;
        Pair<unsigned int, const PoliceReport&> find_report = reports_directory.find(report_number);
        if (find_report.first == 0) {
            return Pair<unsigned int, std::vector<std::reference_wrapper<const PoliceReport>>>(0, result);
        }
        result.push_back(std::ref(find_report.second));
        return Pair<unsigned int, std::vector<std::reference_wrapper<const PoliceReport>>>(find_report.first, result);
    };

    
    Pair<unsigned int, std::vector<std::reference_wrapper<const Investigation>>> find_investigations_by_number(const unsigned int& report_number) const{
        std::vector<std::reference_wrapper<const Investigation>> investigations;
        Pair<unsigned int, const List<unsigned int>&> find_indices = investigations_directory.find(report_number);
        if (find_indices.first == 0) {
            return Pair<unsigned int, std::vector<std::reference_wrapper<const Investigation>>>(0, investigations);
        }

        for (const unsigned int& index : find_indices.second) {
            investigations.push_back(investigations_directory.get_storage().get_element(index));
        }

        return Pair<unsigned int, std::vector<std::reference_wrapper<const Investigation>>>(find_indices.first, investigations);
    }

    const Pair<unsigned int, const List<unsigned int>&> find_indicies_investigations_by_report_number(unsigned int report_number) const{
        return investigations_directory.find(report_number);
    }
   

    std::vector<Pair<const PoliceReport&, const Investigation&>> filter_directories(const Date& date, const Status status, const FullName& applicant) const  {
        std::vector<Pair<const PoliceReport&, const Investigation&>> result;
        Pair<unsigned int, const List<unsigned int>&> filtered_date_indices = investigations_directory.find_date(date);
        if (filtered_date_indices.first == 0) {
            return result;
        }

        for (const unsigned int& index : filtered_date_indices.second) {
            const Investigation& investigation = investigations_directory.get_storage().get_element(index);
            if (investigation.investigation_status != status) {
                continue;
            }

            Pair<unsigned int, const PoliceReport&> find_report = reports_directory.find(investigation.report_number);
            if (find_report.first == 0) {
                continue; 
            }

            if (find_report.second.applicant == applicant) {
                result.push_back(Pair<const PoliceReport&, const Investigation&>(find_report.second, investigation));
            }
        }
        return result;
    }

    const InterfaceStorage<PoliceReport>& get_reports_storage() const{
        return reports_directory.get_storage();
    }

    const InterfaceStorage<Investigation>& get_investigations_storage() const{
        return investigations_directory.get_storage();
    }

    void clear_reports_directory(){
        reports_directory.clear();
    }

    void clear_investigations_directory(){
        investigations_directory.clear();
    }

    void set_capacity_hash_table_reports_directory(unsigned int n){
        reports_directory.set_capacity(n);
    }

    void print_console_storage_reports() const{
        reports_directory.print_storage();
    }
    void print_console_hash_table_reports() const{
        reports_directory.print_data_structure_index();
    }

    void print_console_storage_investigations() const{
        investigations_directory.print_storage();
    }

    void print_console_tree_investigations() const{
        investigations_directory.print_data_structure_index();
    }

    void print_console_tree_dates()const{
        investigations_directory.print_tree_dates();
    }

    std::string hash_table_reports_to_string() const{
        return reports_directory.hash_table_to_string();
    }

    std::string storage_reports_to_string() const{
        return reports_directory.storage_to_string();
    }

    std::string tree_investigations_to_string() const{
        return investigations_directory.tree_investigations_to_string();
    }

    std::string tree_dates_to_string() const{
        return investigations_directory.tree_dates_to_string();
    }

    std::string storage_investigations_to_string() const{
        return investigations_directory.storage_to_string();
    }

    unsigned int get_hash(const unsigned int& key) const{
        return reports_directory.get_hash(key);
    }
};
