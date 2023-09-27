#include "MaintenanceEmployee.h"

const int MaintenanceEmployee::SALARY_PER_HOUR = 30;

MaintenanceEmployee::MaintenanceEmployee(const char* name, int salary, int bonus):
	Employee(name,salary), bonusPerCall(bonus)
{}

void MaintenanceEmployee::setBonusPerCall(int bonus)
{
    if (bonus < 0)
        throw GeneralException("The employee bonus can't be neagtive");

    bonusPerCall = bonus;
}

int MaintenanceEmployee::calculateSalary() const
{
    int newSalary = sSalary + (numOfCalls * bonusPerCall);
    return newSalary;
}

void MaintenanceEmployee::show(ostream& out) const
{
    if ((pName == nullptr))
        out << "Error in Maintenance Employee information" << endl;
    else
        out << "[" << pName << " earn " << sSalary << ", and had " << numOfCalls << " maintenance calls. he also get " << bonusPerCall << " for each call]" << endl;
}