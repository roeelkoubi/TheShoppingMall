#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"

Product::Product(const char* name, int id, int price_a):
		iID(id), price(price_a), pName(nullptr)
{
	pName = _strdup(name);
}

Product::~Product()
{
	if (pName)
		delete[]pName;
}

Product::Product(Product& product)
{
	*this = product;
}

Product::Product(Product&& product) noexcept
{
	*this = product;
}

const Product& Product::operator=(const Product& other)
{
	if (this == &other)
		return *this;

	iID = other.iID;
	price = other.price;
	setName(other.pName);
	return *this;
}

const Product& Product::operator=(Product&& other) noexcept 
{
	if (this == &other)
		return *this;

	iID = other.iID;
	swap(pName,other.pName);
	return *this;
}

bool Product::operator==(const Product& other) const
{
	if (iID == other.getPID())
		return false;

	return true;
}

void Product::setName(const char* name)
{
	if (name == nullptr)
		throw NullValException("name");

	if (pName != nullptr)
		delete[]pName;

	pName = _strdup(name);
}

void Product::setPrice(int price_a)
{
	if (price_a < 0)
		throw GeneralException("invalid price to product, cannot be negative");
	else
		price = price_a;
}

void Product::show(ostream& out) const
{
	if ((pName == nullptr))
		out << "Error in Product information" << endl;
	else
		out << "[Product " << pName << " with ID " << iID << ", cost " << price << "]" << endl;	
}