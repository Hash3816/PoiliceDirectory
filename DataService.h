#pragma once
#include <QRegularExpression>
#include <QString>
#include <vector> //Пока пусть просто вектор будет, потом Qvector
#include "IStorage.h"
#include "./tree/DataManagerTree.h"
#include "./hash_table/DataManagerHashTable.h"
#include "DynamicArray.h"
#include "./hash_table/hash_table.h"
#include "./tree/rb_tree.h"

class DataService{
private:
    DataManagerHashTable reports_directory;
    DataManagerTree investigations_directory;

    DataService() :
        reports_directory(new DynamicArray<PoliceReport>, new HashTable<unsigned int, unsigned int>),
        investigations_directory(new DynamicArray<Investigation>, new RB_tree<unsigned int, unsigned int>,
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


    //Всё получили InterfaceStorage можно рисовать 1 справочник
    //При загрузке справочника нужно диалоговое окно 
    // "вы уверены что хотите загрузить новый справочник все несохранённые данные будут стёрты"
    const InterfaceStorage<PoliceReport>& load_reports_from_file(const std::string& path){
      
        reports_directory.load_data_from_file(path);
        return reports_directory.get_storage();
    }
    const InterfaceStorage<Investigation>& load_investigations_from_file(const std::string& path) {
        investigations_directory.load_data_from_file(path);
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
            throw std::runtime_error("Неверно введён номер заявки.");
        }

        //Перенести код в отдельный метод
        if(report.applicant.name.empty()){
            throw std::runtime_error("Поле имя пусто.");
        }
        if(report.applicant.surname.empty()){
            throw std::runtime_error("Поле фамилия пусто.");
        }
        if(report.applicant.patronymic.empty()){
            throw std::runtime_error("Поле отчество пусто.");
        }


        QString surname = QString::fromStdString(report.applicant.surname);
        QString name = QString::fromStdString(report.applicant.name);
        QString patronymic = QString::fromStdString(report.applicant.patronymic);
        QString description = QString::fromStdString(report.description);

        if(name.size() > 50){
            throw std::runtime_error("Поле имя превышает допустимый размер.");
        }

        if(surname.size() > 50){
            throw std::runtime_error("Поле фамилия превышает допустимый размер.");
        }

        if(patronymic.size() > 50){
            throw std::runtime_error("Поле отчество превышает допустимый размер.");
        }

        if(description.size() > 100){
            throw std::runtime_error("Поле описание превышает допустимый размер.");
        }

        if(!surname[0].isUpper()){
            throw std::runtime_error("Фамилия должна начинаться с заглавной буквы.");
        }
        if(!name[0].isUpper()){
            throw std::runtime_error("Имя должно начинаться с заглавной буквы.");
        }
        if(!patronymic[0].isUpper()){
            throw std::runtime_error("Отчество должно начинаться с заглавной буквы.");
        }

        if(name[name.size()-1].isUpper() && (name.size() != 1)){
            throw std::runtime_error("Имя не должно оканичваться на заглавную букву.");
        }
        if(surname[surname.size()-1].isUpper() && (surname.size() != 1)){
            throw std::runtime_error("Фамилия не должна оканичваться на заглавную букву.");
        }
        if(patronymic[patronymic.size()-1].isUpper() && (patronymic.size() != 1)){
            throw std::runtime_error("Отчество не должно оканичваться на заглавную букву.");
        }

        if(name[name.size()-1] == "-"){
            throw std::runtime_error("Имя не должно оканичваться на дефис.");
        }
        if(surname[surname.size()-1] == "-"){
            throw std::runtime_error("Фамилия не должна оканичваться на дефис.");
        }
        if(patronymic[patronymic.size()-1] == "-"){
            throw std::runtime_error("Отчество не должно оканичваться на дефис.");
        }

        unsigned int count_dash = 0;
        unsigned int count_upper_symbols = 1; // первая заглавная буква
        for(unsigned int i = 1; i < surname.size() - 1; i++){ //от 2 до предпоследнего символа
            if(surname[i] == "-" && !surname[i + 1].isUpper()){
                throw std::runtime_error("В фамилии после дефиса должна  начинаться заглавная буква.");
            }
            if(surname[i] == "-"){
                count_dash += 1;
            }
            if(count_dash > 3){
                throw std::runtime_error("Превышено максимальное количество дефисов в фамилии.");
            }
            if(surname[i].isUpper() && surname[i - 1] != "-"){
                throw std::runtime_error("Не считая первого символа фамилии, перед заглавной буквой должен быть дефис.");
            }
            if(surname[i].isUpper()){
                count_upper_symbols += 1;
            }
            if(count_upper_symbols > 4){
                throw std::runtime_error("Превышено максимальное количество заглавных букв в фамилии.");
            }
        }

        count_dash = 0;
        count_upper_symbols = 1; // первая заглавная буква
        for(unsigned int i = 1; i < name.size() - 1; i++){ //от 2 до предпоследнего символа
            if(name[i] == "-" && !name[i + 1].isUpper()){
                throw std::runtime_error("В имени после дефиса должна начинаться заглавная буква.");
            }
            if(name[i] == "-"){
                count_dash += 1;
            }
            if(count_dash > 3){
                throw std::runtime_error("Превышено максимальное количество дефисов в имени.");
            }
            if(name[i].isUpper() && name[i - 1] != "-"){
                throw std::runtime_error("Не считая первого символа имени, перед заглавной буквой должен быть дефис.");
            }
            if(name[i].isUpper()){
                count_upper_symbols += 1;
            }
            if(count_upper_symbols > 4){
                throw std::runtime_error("Превышено максимальное количество заглавных букв в имени.");
            }
        }

        count_dash = 0;
        count_upper_symbols = 1; // первая заглавная буква
        for(unsigned int i = 1; i < patronymic.size() - 1; i++){ //от 2 до предпоследнего символа
            if(patronymic[i] == "-" && !patronymic[i + 1].isUpper()){
                throw std::runtime_error("В отчестве после дефиса должна начинаться заглавная буква.");
            }
            if(patronymic[i] == "-"){
                count_dash += 1;
            }
            if(count_dash > 3){
                throw std::runtime_error("Превышено максимальное количество дефисов в отчестве.");
            }
            if(patronymic[i].isUpper() && patronymic[i - 1] != "-"){
                throw std::runtime_error("Не считая первого символа отчества, перед заглавной буквой должен быть дефис.");
            }
            if(patronymic[i].isUpper()){
                count_upper_symbols += 1;
            }
            if(count_upper_symbols > 4){
                throw std::runtime_error("Превышено максимальное количество заглавных букв в отчестве.");
            }
        }

        QRegularExpression allowedRegex("^[а-яА-ЯёЁ-]+$");
        if (!allowedRegex.match(surname).hasMatch()) {
            throw std::runtime_error("Фамилия может содержать только русские буквы и дефис.");
        }
        if (!allowedRegex.match(name).hasMatch()) {
            throw std::runtime_error("Имя может содержать только русские буквы и дефис.");
        }
        if (!allowedRegex.match(patronymic).hasMatch()) {
            throw std::runtime_error("Отчество может содержать только русские буквы и дефис.");
        }
        reports_directory.append(report); //Заявление может быть дубликатом обработать исключение в ui с выводом сообщения
    };
    void del_report(const PoliceReport& report, unsigned int index) {
        //Тут хоть и неочевидно, но лучше сначала проверить ведут ли с следователи эту заявку, проверить это
        //Сначала спросить у пользователя готов ли он удалять следователей с заявки в 2 справочнике,
        // Можно их вывести списком в диалоговом окне
        // если пользователь согласен  вызвать метод удаления заявок в цикле
        // потом вызвать метод удаления этой заявки
        //Также может оказаться что заявки вообще нет, поэтому в ui вызывать метод find перед вызовом 
        reports_directory.erase(report, index);
    }

  
    void add_investigation(const Investigation& investigation) {
        if (reports_directory.find(investigation.report_number).first == 0) {
            throw std::runtime_error("В справочнике заявлений не найден номер заявления.");
        }

        investigations_directory.append(investigation);
    };
    void del_investigation(const Investigation& investigation, unsigned int index){
        try {
            investigations_directory.erase(investigation, index);
        }
        catch (std::runtime_error error) {
            if ((std::string(error.what()) == "index out of range") || (std::string(error.what()) == "invalid index")) {
                throw std::runtime_error("Неверно введен номер строки следствия или следствие не существует.");
            }
            throw error;
        }
    };


    Pair<unsigned int, std::vector<std::reference_wrapper<const PoliceReport>>> find_report_data(const unsigned int& report_number) const{
        if(report_number < 1 || report_number > 9999){
            throw std::runtime_error("Неверный номер заявления.");
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

};
