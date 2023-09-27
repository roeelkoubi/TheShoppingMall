#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingMall.h"

ShoppingMall::ShoppingMall(const char* name, Address& add,int employeeLSize,int storeLSize):
	aAddress(add), employeeListSize(employeeLSize), storeListSize(storeLSize)
{
	storeList = new Store * [storeListSize];
    employeeList = new Employee * [employeeListSize];
    pName = _strdup(name);
}

ShoppingMall::~ShoppingMall()
{
    delete[] pName;

    for (int i = 0; i < storeCounter; i++)
        delete storeList[i];
    delete storeList;

    for (int i = 0; i < employeeCounter; i++)
        delete employeeList[i];
    delete employeeList;
}

void ShoppingMall::maintenanceCallAlert(Store* sTemp, char* type)
{
    bool loop = true;
    time_t currentTime = time(nullptr);
    char* timeString = ctime(&currentTime);
    while (loop)
    {
        int randomNumber = rand() % (employeeCounter);
        const type_info& typeInfo = typeid(employeeList[randomNumber]);
        if (typeid(*employeeList[randomNumber]) == typeid(MaintenanceEmployee))
        {
            MaintenanceEmployee* maintenanceEmp = dynamic_cast<MaintenanceEmployee*>(employeeList[randomNumber]);
            maintenanceEmp->maintanceCall();

            cout << "We got new maintenance Call Alert at " << sTemp->getName() << endl;
            cout << employeeList[randomNumber]->getName() << " Take care of this call" << endl;
            cout << "Current time: " << timeString;
            cout << "reason of the call: " << type << endl;
            loop = false;
        }
    }
}

void ShoppingMall::setName(const char* name)
{
    if (name == nullptr)
        throw NullValException("name");

    if (pName != nullptr)
        delete[]pName;

    pName = _strdup(name);
}

bool ShoppingMall::addStore(Store* store)
{
    if (storeCounter == storeListSize)
        return false;

    storeList[storeCounter++] = store;
    return true;
}

bool ShoppingMall::addEmployee(Employee* emp)
{
    if (employeeCounter == employeeListSize)
        return false;

    employeeList[employeeCounter++] = emp;
    return true;
}

void ShoppingMall::showAllStores() const
{
    for (int i = 0; i < storeCounter; i++)
    {
        cout << i + 1 << ". ";
        storeList[i]->show(cout);
    }
}

void ShoppingMall::showAllEmployees() const
{
    for (int i = 0; i < employeeCounter; i++)
    {
        cout << i + 1 << ". ";
        employeeList[i]->show(cout);
    }
}

void ShoppingMall::show(ostream& out) const
{
    int counter = 0;
    out << "Shopping Mall Name: " << pName << endl;
    out << "Address " << aAddress <<endl;
    out << endl;
    out << "Employees that working in this shooping mall: " << endl;
    showAllEmployees();
    out << endl;
    for (int i = 0; i < storeCounter; i++)
    {
        counter += storeList[i]->getNumOfEmployes();
        out << "Store " << storeList[i]->getName() << " Has the following employees: " << endl;
        storeList[i]->showAllEmployeesInStore();
        out << endl;
    }
    out << endl;
    out << "In this shopping mall there are " << counter << " employees in " << storeCounter << " diffrent stores" << endl;
}