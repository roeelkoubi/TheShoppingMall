#include "StoreEmployee.h"

StoreEmployee::StoreEmployee(const char* name, int salary, Store* store):
	Employee(name,salary),pStore(store)
{}

void StoreEmployee::setStore(const Store* Store)
{
    pStore = Store;
}

void StoreEmployee::setNumOfSales(int numOfSale)
{
    if (numOfSale < 0)
        throw GeneralException("Number of sales cannot be negative");
    
    numOfSales = numOfSales;
}

int StoreEmployee::calculateSalary() const
{
    int new_salary = sSalary + (numOfSales * 50);
    return new_salary;
}

void StoreEmployee::show(ostream& out) const
{
    if ((pName == nullptr))
        out << "Error in Store Employee information" << endl;
    else
        out << "[" << pName << " earn " << sSalary << ", and had " << numOfSales << " num of sales]" << endl;
}
