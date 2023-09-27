#pragma once
#include <iostream>
using namespace std;
#include "MallExceptions.h"

class Product
{

private:
	char*	pName;
	int		iID;
	int		price;


public:
	Product(const char* name, int id, int price_a);
	Product(Product& product);
	Product(Product&& product) noexcept;
	~Product();

	const Product&	operator=(const Product& other);
	const Product&	operator=(Product&& other) noexcept;
	bool			operator==(const Product& other) const;

	const char*		getName() const { return pName; }
	int				getPID() const { return iID; } 
	int				getPrice() const { return price; }
	void			setName(const char* name);
	void			setPrice(int price_a);
	void			show(ostream& out) const;
};

