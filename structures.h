#pragma once
#include <iostream>


enum class Month{
    jan = 1, feb, mar, apr,may,jun,
    jul,aug,sep,oct,nov,dec,
};


struct Date{
    unsigned int day;
    Month month;
    unsigned int year;
    
    Date() = default;
    Date(unsigned int day, Month month, unsigned int year):
    day(day), month(month), year(year){}

    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
};
std::ostream& operator<<(std::ostream& os, const Date& date);
std::string month_to_string(Month month);
Month string_to_month(const std::string& str);
std::string date_to_string(const Date& date);

struct FullName {
	std::string surname;
	std::string name;
	std::string patronymic;

    FullName()= default;
    FullName(std::string surname, std::string name, std::string patronymic):
        surname(surname), name(name), patronymic(patronymic){};

    bool operator<(const FullName& other) const;
    bool operator>(const FullName& other) const;
    bool operator==(const FullName& other) const;
    bool operator!=(const FullName& other) const;
    bool operator<=(const FullName& other) const;
    bool operator>=(const FullName& other) const;
};

std::string full_name_to_string(const FullName& full_name);

struct PoliceReport {
    unsigned int report_number;
    FullName applicant;
    std::string description;

    PoliceReport() = default;
    PoliceReport(unsigned int report_number, FullName applicant, std::string description) {
        this ->report_number = report_number;
        this->applicant = applicant;
        this->description = description;
    }

    bool operator<(const PoliceReport& other) const;
    bool operator>(const PoliceReport& other) const;
    bool operator==(const PoliceReport& other) const;
    bool operator<=(const PoliceReport& other) const;
    bool operator>=(const PoliceReport& other) const;
    bool operator!=(const PoliceReport& other) const;
};

std::ostream& operator<<(std::ostream& os, const PoliceReport& report);
std::string info_to_string(const PoliceReport& report);
PoliceReport string_to_report(const std::string& report);



enum class Status{
    closed,
    on_hold,
    under_review,
    active,
};
std::string status_to_string(Status status);
Status string_to_status(const std::string& str);

struct Investigation{
    unsigned int report_number;
    FullName investigator;
    Status investigation_status;
    Date initiation_date;

    Investigation() = default;
    Investigation(unsigned int report_number,FullName investigator,
                  Status investigation_status, Date initiation_date){
        this->report_number = report_number;
        this->investigator = investigator;
        this->investigation_status = investigation_status;
        this->initiation_date = initiation_date;
    };

    bool operator<(const Investigation& other) const;
    bool operator>(const Investigation& other) const;
    bool operator==(const Investigation& other) const;
    bool operator<=(const Investigation& other) const;
    bool operator>=(const Investigation& other) const;
    bool operator!=(const Investigation& other) const;
};

std::ostream& operator<<(std::ostream& os, const Investigation& investigation);
std::string info_to_string(const Investigation& investigation);
Investigation string_to_investigation(const std::string& investigation);

