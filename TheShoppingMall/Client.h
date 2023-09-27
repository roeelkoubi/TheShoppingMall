#pragma once
#include <iostream>
#include "Address.h"
#include "Product.h"
#include "MallExceptions.h"
using namespace std;

class Product;

class Client
{
private:
	char*			pName;
	char*			pId;
	int				bBudget;
	int				numOfProducts = 0;
	Address			pAddress;
	const Product** boughtProducts;
	

public:
	static const int SIZE;
	Client(const char* name, const char* id, int budget, Address& address);
	Client(Client &Client) = delete;
	Client(Client &&Client) = delete;
	~Client();

	const Client& operator=(const Client& other) = delete;
	const Client& operator=(Client&& other) = delete;

	const char*		getName() const { return pName; }
	const char*		getID() const { return pId; }
	int				getBudget() const { return bBudget; }
	const Product** getProductList() const { return boughtProducts; } 
	const Address	getAddress() const { return pAddress; }
	int				getNumOfProducts() const { return numOfProducts; }
	void			setName(const char* name);
	void			setId(const char* id);
	void			setBudget(int budget_c);
	void			setAddress(const Address& address_n);
	bool			buyProduct(Product* prod);
	void			show(ostream& out) const;
};

