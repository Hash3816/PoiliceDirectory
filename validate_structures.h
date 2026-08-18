#ifndef VALIDATE_STRUCTURES_H
#define VALIDATE_STRUCTURES_H
#include "structures.h"
#include "QString"

void validate_police_report_structure(const PoliceReport& report);
void validate_full_name(const FullName& full_name);
FullName validate_full_name(const QString& full_name);
Date validate_date_string(const QString& date);
void validate_investigation_structure(const Investigation& investigation);

#endif // VALIDATE_STRUCTURES_H
