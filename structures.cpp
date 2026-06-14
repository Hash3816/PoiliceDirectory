#include "structures.h"
#include <string>
#include <sstream>
#include <stdexcept>


bool Date::operator<(const Date& other) const {
    if (year != other.year) {
        return year < other.year;
    }
    if (month != other.month) {
        return month < other.month;
    }
    return day < other.day;
}
bool Date::operator>(const Date& other) const {
    if (year != other.year) {
        return year > other.year;
    }
    if (month != other.month) {
        return month > other.month;
    }
    return day > other.day;
}
bool Date::operator==(const Date& other) const {
    return (year == other.year) && (month == other.month) && (day == other.day);
}
bool Date::operator!=(const Date& other) const {
    return !((year == other.year) && (month == other.month) && (day == other.day));
}
bool Date::operator<=(const Date& other) const {
    return (*this == other) || (*this < other);
}
bool Date::operator>=(const Date& other) const {
    return (*this == other) || (*this > other);
}
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << " " << month_to_string(date.month) << " " << date.year;
    return os;
}

std::string date_to_string(const Date& date){
    std::stringstream ss_stream;
    ss_stream << date;
    return ss_stream.str();
}



bool FullName::operator<(const FullName& other) const {
    if (surname != other.surname){
        return surname < other.surname;
    }
    if (name != other.name){
        return name < other.name;
    }

    return patronymic < other.patronymic;
}

bool FullName::operator>(const FullName& other) const {
    if (surname != other.surname){
        return surname > other.surname;
    }
    if (name != other.name){ 
        return name > other.name;
    }

    return patronymic > other.patronymic;
}

bool FullName::operator==(const FullName& other) const {
    return (surname == other.surname) && (name == other.name) && (patronymic == other.patronymic);
}
bool FullName::operator!=(const FullName& other) const {
    return !((surname == other.surname) && (name == other.name) && (patronymic == other.patronymic));
}
bool FullName::operator<=(const FullName& other) const {
    return *this == other || *this < other;
}
bool FullName::operator>=(const FullName& other) const {
    return *this == other || *this > other;
}



bool PoliceReport::operator!=(const PoliceReport& other) const {
    return !(*this == other);
}

bool PoliceReport::operator<(const PoliceReport& other) const {
    if (report_number != other.report_number) return report_number < other.report_number;
    return applicant < other.applicant;
}

bool PoliceReport::operator>(const PoliceReport& other) const {
    if (report_number != other.report_number) return report_number > other.report_number;
    return applicant > other.applicant;
}

bool PoliceReport::operator==(const PoliceReport& other) const {
    return report_number == other.report_number && applicant == other.applicant;
}

bool PoliceReport::operator<=(const PoliceReport& other) const {
    return *this == other || *this < other;
}
bool PoliceReport::operator>=(const PoliceReport& other) const {
    return *this == other || *this > other;
}


bool Investigation::operator==(const Investigation& other) const {
    return report_number == other.report_number && investigator == other.investigator;
}

bool Investigation::operator!=(const Investigation& other) const {
    return !(*this == other);
}

bool Investigation::operator<(const Investigation& other) const {
    if (report_number != other.report_number) {
        return report_number < other.report_number;
    }

    return investigator < other.investigator;
}

bool Investigation::operator>(const Investigation& other) const {
    if (report_number != other.report_number) {
        return report_number > other.report_number;
    }

    return investigator > other.investigator;
}

bool Investigation::operator<=(const Investigation& other) const {
    return *this == other || *this < other;
}

bool Investigation::operator>=(const Investigation& other) const {
    return *this == other || *this > other;
}

std::ostream& operator<<(std::ostream& os, const PoliceReport& report) {
    return os << info_to_string(report);
}



std::string full_name_to_string(const FullName& full_name){
    return full_name.surname + " " + full_name.name + " " + full_name.patronymic;
}

std::string status_to_string(Status status) {
    switch (status) {
    case Status::active:       return "возбуждено";
    case Status::under_review: return "на рассмотрении";
    case Status::on_hold:      return "приостановлено";
    case Status::closed:       return "закрыто";
        throw std::runtime_error("Невозможно вывести статус из справочника. Строка повреждена.");
    }
}

Status string_to_status(const std::string& str) {
    if (str == "возбуждено")      return Status::active;
    if (str == "на рассмотрении") return Status::under_review;
    if (str == "приостановлено") return Status::on_hold;
    if (str == "закрыто")         return Status::closed;
    throw std::runtime_error("Некорректный статус.");
}

std::string month_to_string(Month month) {
    switch (month) {
    case Month::jan: return "янв"; case Month::feb: return "фев";
    case Month::mar: return "мар"; case Month::apr: return "апр";
    case Month::may: return "май"; case Month::jun: return "июн";
    case Month::jul: return "июл"; case Month::aug: return "авг";
    case Month::sep: return "сен"; case Month::oct: return "окт";
    case Month::nov: return "ноя"; case Month::dec: return "дек";
        throw std::runtime_error("Невозможно вывести строку из справочника. Строка повреждена.");
    }
}

Month string_to_month(const std::string& str) {
    if (str == "янв") return Month::jan; if (str == "фев") return Month::feb;
    if (str == "мар") return Month::mar; if (str == "апр") return Month::apr;
    if (str == "май") return Month::may; if (str == "июн") return Month::jun;
    if (str == "июл") return Month::jul; if (str == "авг") return Month::aug;
    if (str == "сен") return Month::sep; if (str == "окт") return Month::oct;
    if (str == "ноя") return Month::nov; if (str == "дек") return Month::dec;
    throw std::runtime_error("Введен неверный месяц.");
}


std::string info_to_string(const PoliceReport& report) {
    return std::to_string(report.report_number) + " " +
           report.applicant.surname + " " +
           report.applicant.name + " " +
           report.applicant.patronymic + " " +
           report.description;
}

PoliceReport string_to_report(const std::string& str_report) {
    std::stringstream ss(str_report);
    std::string s_number;
    PoliceReport report;

    if (!(ss >> s_number >> report.applicant.surname >> report.applicant.name >> report.applicant.patronymic)) {
        throw std::runtime_error("Некорректный формат строки заявления");
    }

    std::getline(ss >> std::ws, report.description);

    try {
        int num = std::stoi(s_number);
        if (num <= 0) throw std::runtime_error("invalid num");
        report.report_number = static_cast<unsigned int>(num);
    } catch (...) {
        throw std::runtime_error("Invalid number report");
    }

    return report;
}


std::string info_to_string(const Investigation& investigation) {
    return std::to_string(investigation.report_number) + " " +
           investigation.investigator.surname + " " +
           investigation.investigator.name + " " +
           investigation.investigator.patronymic + " " +
           status_to_string(investigation.investigation_status) + " " +
           std::to_string(investigation.initiation_date.day) + " " +
           month_to_string(investigation.initiation_date.month) + " " +
           std::to_string(investigation.initiation_date.year);
}

std::ostream& operator<<(std::ostream& os, const Investigation& investigation) {
    return os << info_to_string(investigation);
}

Investigation string_to_investigation(const std::string& str_investigation) {
    std::stringstream ss(str_investigation);
    std::string s_num, s_status, s_day, s_month, s_year;
    Investigation inv;

    if (!(ss >> s_num >> inv.investigator.surname >> inv.investigator.name >> inv.investigator.patronymic)) {
        throw std::runtime_error("Некорректная структура строки расследования (ФИО)");
    }

    ss >> s_status;
    if (s_status == "на") {
        std::string s_status_part2;
        ss >> s_status_part2;
        s_status += " " + s_status_part2;
    }

    if (!(ss >> s_day >> s_month >> s_year)) {
        throw std::runtime_error("Некорректная структура строки расследования (Дата)");
    }

    try {
        int num = std::stoi(s_num);
        if (num <= 0) throw std::runtime_error("");
        inv.report_number = static_cast<unsigned int>(num);
    } catch (...) { throw std::runtime_error("Некорректный номер заявления"); }

    inv.investigation_status = string_to_status(s_status);

    try {
        int day = std::stoi(s_day);
        if (day <= 0 || day > 31) throw std::runtime_error("");
        inv.initiation_date.day = day;
    } catch (...) { throw std::runtime_error("Некорректный день"); }

    inv.initiation_date.month = string_to_month(s_month);

    try {
        int year = std::stoi(s_year);
        if (year < 2024 || year > 2026) throw std::runtime_error("");
        inv.initiation_date.year = year;
    } catch (...) { throw std::runtime_error("Некорректный год"); }

    return inv;
}