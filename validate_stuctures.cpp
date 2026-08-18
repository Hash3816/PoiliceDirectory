#include "structures.h"
#include <QRegularExpression>
#include <Qstring>
#include <QDate>

void validate_full_name(const FullName& full_name){ //Длина фамилии, имени, отчества от 1 до 50
    if(full_name.name.empty()){
        throw std::runtime_error("Поле имя пусто.");
    }
    if(full_name.surname.empty()){
        throw std::runtime_error("Поле фамилия пусто.");
    }
    if(full_name.patronymic.empty()){
        throw std::runtime_error("Поле отчество пусто.");
    }


    QString surname = QString::fromStdString(full_name.surname);
    QString name = QString::fromStdString(full_name.name);
    QString patronymic = QString::fromStdString(full_name.patronymic);


    if(name.size() > 50){
        throw std::runtime_error("Поле имя превышает допустимый размер.");
    }

    if(surname.size() > 50){
        throw std::runtime_error("Поле фамилия превышает допустимый размер.");
    }

    if(patronymic.size() > 50){
        throw std::runtime_error("Поле отчество превышает допустимый размер.");
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
        throw std::runtime_error("Имя не должно оканчиваться на заглавную букву.");
    }
    if(surname[surname.size()-1].isUpper() && (surname.size() != 1)){
        throw std::runtime_error("Фамилия не должна оканчиваться на заглавную букву.");
    }
    if(patronymic[patronymic.size()-1].isUpper() && (patronymic.size() != 1)){
        throw std::runtime_error("Отчество не должно оканчиваться на заглавную букву.");
    }

    if(name[name.size()-1] == "-"){
        throw std::runtime_error("Имя не должно оканчиваться на дефис.");
    }
    if(surname[surname.size()-1] == "-"){
        throw std::runtime_error("Фамилия не должна оканчиваться на дефис.");
    }
    if(patronymic[patronymic.size()-1] == "-"){
        throw std::runtime_error("Отчество не должно оканчиваться на дефис.");
    }

    unsigned int count_dash = 0; //MAX 1
    unsigned int count_upper_symbols = 1; // первая заглавная буква(MAX 2)
    for(unsigned int i = 1; i < surname.size() - 1; i++){ //от 2 до предпоследнего символа
        if(surname[i] == "-" && !surname[i + 1].isUpper()){
            throw std::runtime_error("В фамилии после дефиса должна начинаться заглавная буква.");
        }
        if(surname[i] == "-"){
            count_dash += 1;
        }
        if(count_dash > 1){
            throw std::runtime_error("Превышено максимальное количество дефисов в фамилии.");
        }
        if(surname[i].isUpper() && surname[i - 1] != "-"){
            throw std::runtime_error("Не считая первого символа фамилии, перед заглавной буквой должен быть дефис.");
        }
        if(surname[i].isUpper()){
            count_upper_symbols += 1;
        }
        if(count_upper_symbols > 2){
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
        if(count_dash > 1){
            throw std::runtime_error("Превышено максимальное количество дефисов в имени.");
        }
        if(name[i].isUpper() && name[i - 1] != "-"){
            throw std::runtime_error("Не считая первого символа имени, перед заглавной буквой должен быть дефис.");
        }
        if(name[i].isUpper()){
            count_upper_symbols += 1;
        }
        if(count_upper_symbols > 2){
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
        if(count_dash > 1){
            throw std::runtime_error("Превышено максимальное количество дефисов в отчестве.");
        }
        if(patronymic[i].isUpper() && patronymic[i - 1] != "-"){
            throw std::runtime_error("Не считая первого символа отчества, перед заглавной буквой должен быть дефис.");
        }
        if(patronymic[i].isUpper()){
            count_upper_symbols += 1;
        }
        if(count_upper_symbols > 2){
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
}

Date validate_date_string(const QString& date){
    if(date.size() != 11){
        throw std::runtime_error("Некорректная длина поля даты.");
    }

    if(!date[0].isDigit() || !date[1].isDigit()){
        throw std::runtime_error("Некорректно введен день в поле даты.");
    }

    QString q_day = date[0];
    q_day += date[1];

    unsigned int day_num = q_day.toInt();

    if(date[2] != " "){
        throw std::runtime_error("День и месяц должны разделяться пробелом.");
    }

    if((day_num < 1) || (day_num > 31)){
        throw std::runtime_error("Некорректно введён день в поле дата.");
    }

    QString q_month = date[3];
    q_month += date[4];
    q_month += date[5];


    std::string s_month = q_month.toStdString();

    Month month;
    try{
        month = string_to_month(s_month);
    }
    catch(std::runtime_error){
        throw std::runtime_error("Некорректно введён месяц.");
    }

    unsigned int month_num = int(month);

    if(date[6] != " "){
        throw std::runtime_error("Месяц и год должны разделяться пробелом.");
    }

    if(!date[7].isDigit() || !date[8].isDigit() || !date[9].isDigit() ||!date[10].isDigit()){
        throw std::runtime_error("Некорректно введён год.");
    }

    QString q_year = date[7];
    q_year += date[8];
    q_year += date[9];
    q_year += date[10];

    unsigned int year_num = q_year.toInt();
    if(year_num < 2024){
        throw std::runtime_error("Минимальный возможный год возбуждения следствия 2024-ый.");
    }

    QDate q_date = QDate(year_num, month_num, day_num);
    if( q_date > QDate::currentDate()){
        throw std::runtime_error("Дата начала следствия не может быть позже текущей даты.");
    }

    if(!q_date.isValid()){
        throw std::runtime_error("Некорректная дата.");
    }
    return Date(day_num, month, year_num);
}



FullName validate_full_name(const QString& q_full_name){
    if(q_full_name.size() == 0){
        throw std::runtime_error("ФИО пусто");
    }
    if(q_full_name.size() > 152){
        throw std::runtime_error("Длина ФИО не должна превышать 152 символа вместе с пробелами.");
    }

    std::string s_full_name = q_full_name.toStdString();

    std::string surname;
    std::string name;
    std::string patronymic;


    int i = 0;
    while(i < s_full_name.size()){
        if(s_full_name[i] ==  ' '){
            i++;
            break;
        }
        surname += s_full_name[i];
        i++;
    }

    while(i < s_full_name.size()){
        if(s_full_name[i] ==  ' '){
            i++;
            break;
        }
        name += s_full_name[i];
        i++;
    }
    while(i < s_full_name.size()){
        patronymic += s_full_name[i];
        i++;
    }

    FullName full_name = FullName(surname, name, patronymic);
    validate_full_name(full_name);

    return full_name;
}