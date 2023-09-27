#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"

Address::Address(const char* city, const char* street, int houseNumber):
    pStreet(nullptr), pCity(nullptr), houseNum(houseNumber)
{
    pCity = _strdup(city);
    pStreet = _strdup(street);
}

Address::~Address()
{
    if (pStreet)
        delete[]pStreet;
    if (pCity)
        delete[]pCity;
}

Address::Address(const Address& address)
{
    *this = address;
}

Address::Address(Address&& address) noexcept:
    houseNum(address.houseNum)
{
    swap(pStreet, address.pStreet);
    swap(pCity, address.pCity);
}

const Address& Address::operator=(const Address& other)
{
    if (this == &other) 
        return *this;

    houseNum = other.houseNum;
    setStreet(other.pStreet);
    setCity(other.pCity);
    return *this;
}

const Address& Address::operator=(Address&& other) noexcept
{
    if (this == &other) 
        return *this;

    houseNum = other.houseNum;
    swap(pStreet, other.pStreet);
    swap(pCity, other.pCity);
    return *this;
}

void Address::setCity(const char* city)
{
    if (city == nullptr)
        throw NullValException("city");

    if (pCity != nullptr)		
        delete[]pCity;

    pCity = _strdup(city);
}

void Address::setStreet(const char* street)
{
    if (street == nullptr)
        throw NullValException("street");

    if (pStreet != nullptr)			
        delete[]pStreet;

    pStreet = _strdup(street); 
}

void Address::setHouseNum(int num)
{
    if (num < 0)
        throw GeneralException("House number can't be negative");

    houseNum = num;
}


ostream& operator<<(ostream& os, const Address& add)
{
    if ((add.pCity == nullptr) || (add.pStreet == nullptr))
        os << "Error in address information" << endl;
    else
        os << add.houseNum << " " << add.pStreet << ", " << add.pCity;
    return os;
}



