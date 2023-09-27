#pragma once
#include <iostream>
#include "MallExceptions.h"
using namespace std;

class Address
{

private:
	char*	pCity;
	char*	pStreet;
	int		houseNum;

public:
	Address(const char* city, const char* street, int houseNumber);
	Address(const Address &address);
	Address(Address&& address) noexcept;
	~Address();

	const Address&	operator=(const Address& other);
	const Address&	operator=(Address&& other) noexcept;
	friend ostream& operator<<(ostream& os, const Address& add);
	const char*		getCity() const { return pCity; }
	const char*		getStreet() const { return pStreet; }
	int				getHouseNum() const { return houseNum; }
	void			setCity(const char* city);
	void			setStreet(const char* street);
	void			setHouseNum(int num);
};


