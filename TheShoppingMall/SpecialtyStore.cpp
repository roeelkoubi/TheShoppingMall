#define _CRT_SECURE_NO_WARNINGS
#include "SpecialtyStore.h"

SpecialtyStore::SpecialtyStore(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a, const char* type):
	Store(name, clientListSize_a, employeeListSize_a, productListSize_a)
{
	merchandiseType = _strdup(type);
}

SpecialtyStore::~SpecialtyStore()
{
	delete[]merchandiseType;
}


void SpecialtyStore::setMerchandiseType(const char* type)
{
	if (type == nullptr)
		throw NullValException("type");

	if (merchandiseType)
		delete[]merchandiseType;

	merchandiseType = _strdup(type);
}

void SpecialtyStore::show(ostream& out) const
{
	if ((pName == nullptr) || (merchandiseType == nullptr))
		out << "Error in Store Entertainmet information" << endl;
	else
		out << "[" << pName << ", Selling " << merchandiseType << "]" << endl;
}

void SpecialtyStore::specialEvent() const
{
	cout << "Starting Lottery - What will be the discount for today?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	unsigned int  discount = (rand() % 10) * 10;
	for (int i = 0; i < numOfProducts; i++)
		productList[i]->setPrice(productList[i]->getPrice() - (productList[i]->getPrice() * discount / 100));

	cout << "Surprise! today's discount is " << discount << "%" << endl;
}







