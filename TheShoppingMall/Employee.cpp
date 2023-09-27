#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

int Employee::eID = 0;

Employee::Employee(const char* name, int salary):
    sSalary(salary)
{
    iId = ++eID;
    pName = _strdup(name);
}

Employee::~Employee()
{
    delete[]pName;
}


void Employee::setName(const char* name)
{
    if (name == nullptr)
        throw NullValException("name");

    if (pName != nullptr)
        delete[]pName;
    else
        pName = _strdup(name);
}

void Employee::setSalary(int salary_e)
{
    if (salary_e < 0)
        throw GeneralException("Salary cannot be negative value");

    sSalary = salary_e;
}

const Employee& Employee::operator>=(const Employee& other) const 
{
    if (getSalary() >= other.getSalary())
        return *this;

    return other;
}

const Employee& Employee::operator<=(const Employee& other) const
{
    if (getID() <= other.getID())
        return *this;

    return other;
}

const Employee& Employee::operator+(int add)
{
    if (add < 0)
        throw GeneralException("Salary addition cannot be negative value");
    
    sSalary +=add;
    return *this;
}