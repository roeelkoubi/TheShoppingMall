#define _CRT_SECURE_NO_WARNINGS
#include "Store.h"

Store::Store(const char* name,int clientListSize_a, int employeeListSize_a, int productListSize_a):
    clientListSize(clientListSize_a),employeeListSize(employeeListSize_a),productListSize(productListSize_a)
{
    pName = _strdup(name);
	clientList = new Client * [clientListSize];
	employeeList = new StoreEmployee * [employeeListSize];
	productList = new Product * [productListSize];
}

Store::~Store()
{
    delete[] pName;
    
    for (int i = 0; i < numOfClients; i++)
        delete clientList[i];
    delete clientList;

    for (int i = 0; i < numOfProducts; i++)
        delete productList[i];
    delete productList;

    for (int i = 0; i < numOfEmployes; i++)
        delete employeeList[i];
    delete employeeList;
}

void Store::setName(const char* name)
{
    if (name == nullptr)
        throw NullValException("name");

    if (pName != nullptr)
        delete[]pName;

    pName = _strdup(name);
}

bool Store::addEmployee(StoreEmployee* emp)
{
    if (numOfEmployes == employeeListSize)
        return false;

    employeeList[numOfEmployes++] = emp;
    return true;
}

void Store::showAllEmployeesInStore() const
{
    if (numOfEmployes == 0)
        cout << "There are no employees in this store" << endl;
    else
    {
        for (int i = 0; i < numOfEmployes; i++)
        {
            cout << i + 1 << ". ";
            employeeList[i]->show(cout);
        }
    }
}

void Store::showAllProducts() const
{
    if (numOfProducts == 0)
        cout << "There are no products in this store" << endl;
    else
    {
        for (int i = 0; i < numOfProducts; i++)
        {
            cout << i + 1 << ". ";
            productList[i]->show(cout);
        }
    }
}

void Store::showAllClients(bool nameOnly) const
{
    if (numOfClients == 0)
        cout << "There are no clients in this store" << endl;
    else
    {
        for (int i = 0; i < numOfClients; i++)
        {
            cout << i + 1 << ". ";
            if (nameOnly)
                cout << clientList[i]->getName() << endl;
            else
                clientList[i]->show(cout);
        }
    }
}

bool Store::addClient(Client* client)
{
    if (numOfClients == clientListSize)
        return false;
    
    clientList[numOfClients++] = client;
    return true;
}

bool Store::addProduct(Product* prod)
{
    if (numOfProducts == productListSize)
        return false;
    
    productList[numOfProducts++] = prod;
    return true;
}

bool Store::checkPID(int id)
{
    for (int i = 0; i < numOfProducts; i++)
        if (productList[i]->getPID() == id)
        {
            cout << "Product ID already exists in this store." << endl;
            return false;
        }

    return true;
}

bool Store::clientBuyProduct(int client, int product)
{
    if (!clientList[client]->buyProduct(productList[product]))
        return false;

    return true;
}