#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"

const int Client::SIZE = 50;

Client::Client(const char* name, const char* id, int budget, Address& address):
    pName(nullptr), pId(nullptr), pAddress(address), bBudget(budget)
{
    pName = _strdup(name);
    pId = _strdup(id);
    boughtProducts = new const Product * [SIZE];
}

Client::~Client()
{
    delete[] pName;
    delete[] pId;
    delete[] boughtProducts; // Products are being freed by Store
}

void Client::setName(const char* name)
{
    if (name == nullptr)
        throw NullValException("name");

    if (pName != nullptr)
        delete[]pName;

    pName = _strdup(name);
}

void Client::setId(const char* id)
{
    if (id == nullptr)
        throw NullValException("id");

    if (pId != nullptr)
            delete[] pId;

    pId = _strdup(id);
}

void Client::setBudget(int budget_c)
{
    if (budget_c < 0)
        throw GeneralException("Budget have to be positive value");

    bBudget = budget_c;
}


void Client::setAddress(const Address& address_n)
{
    pAddress = address_n;
}

bool Client::buyProduct(Product* prod)
{
    if ((bBudget - prod->getPrice()) < 0)
        return false;

    bBudget -= prod->getPrice();
    boughtProducts[numOfProducts++] = prod;
    return true;
}

void Client::show(ostream& out) const
{
    if (pName == nullptr || pId == nullptr || boughtProducts == nullptr)
    {
        out << "Error in client information" << endl;
        return;
    }

    out << "Client: " << endl;
    out << "Name: " << pName << endl;
    out << "ID: " << pId << endl;
    out << "Budget: " << bBudget << endl;
    out << "Number of Bought Products: " << numOfProducts << endl;
    if (numOfProducts > 0)
    {
        out << "Products Bought: " << endl;
        for (int i = 0; i < numOfProducts; i++)
            out << "-> " << boughtProducts[i]->getName() << endl;
    }
    out << "Address: ";
    if (pAddress.getCity() != nullptr)
        out << pAddress.getCity();
    if (pAddress.getStreet() != nullptr)
        out << ", " << pAddress.getStreet();
    out << ", House Number: " << pAddress.getHouseNum() << endl;
}