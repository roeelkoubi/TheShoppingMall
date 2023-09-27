#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"

Restaurant::Restaurant(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a,const char* type):
	Store(name, clientListSize_a, employeeListSize_a, productListSize_a)
{
	foodType = _strdup(type);
}

Restaurant::~Restaurant()
{
	delete[] foodType;
}


void Restaurant::setFoodType(const char* type)
{
	if (type == nullptr)
		throw NullValException("foodType");

	if (foodType)
		delete[]foodType;

	foodType = _strdup(type);
}

void Restaurant::show(ostream& out) const
{
	if ((pName == nullptr) || (foodType == nullptr))
		out << "Error in Resturant information" << endl;
	else
		out << "[The Resturant " << pName << ", Serves " << foodType<< " type of food]" << endl;
}


void Restaurant::specialEvent() const
{
	if (numOfProducts == 0 || numOfClients == 0) {
		cout << "Store must have products and clients to initiate special event." << endl;
		return;
	}

	cout << "Starting Lottery - Who will get a free product?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	int randomProduct = rand() % (numOfProducts);
	int randomClient = rand() % (numOfClients);
	productList[randomProduct]->setPrice(0);
	productList[randomProduct]->show(cout);
	clientList[randomClient]->buyProduct(productList[randomProduct]);
	cout << "Suprise! " << clientList[randomClient]->getName() << " recieved " << productList[randomProduct]->getName() << " on the house" << endl;
}




