#define _CRT_SECURE_NO_WARNINGS
#include "Entertainment.h"


Entertainment::Entertainment(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a, const char* entertainmentType):
	Store(name, clientListSize_a, employeeListSize_a, productListSize_a)
{
	pEntertainmentType = _strdup(entertainmentType);
}

Entertainment::~Entertainment()
{
	delete[]pEntertainmentType;
}


void Entertainment::setEntertainmentType(const char* type)
{
	if (type == nullptr)
		throw NullValException("type");
	
	if (pEntertainmentType)
		delete[]pEntertainmentType;

	if (type)
		pEntertainmentType = _strdup(type);
}

void Entertainment::show(ostream& out) const
{
	if ((pName == nullptr) || (pEntertainmentType == nullptr))
		out << "Error in Store Entertainmet information" << endl;
	else
		out << "[" << pName << ", doing " << pEntertainmentType << "]" << endl;
}

void Entertainment::specialEvent() const
{
	if (numOfProducts == 0 || numOfClients == 0) {
		cout << "Store must have products and clients to initiate special event." << endl;
		return;
	}

	cout << "Starting Lottery - Who will get 50% discount?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	int randomProduct = rand() % (numOfProducts);
	int randomClient = rand() % (numOfClients);
	int price = productList[randomProduct]->getPrice();
	productList[randomProduct]->setPrice(price/2);
	productList[randomProduct]->show(cout);
	clientList[randomClient]->buyProduct(productList[randomProduct]);
	cout << "Suprise! " << clientList[randomClient]->getName() << " recieved 50% discount on " << productList[randomProduct]->getName() << endl;
	productList[randomProduct]->setPrice(price);
}
