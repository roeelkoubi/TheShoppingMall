#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Store.h"
using namespace std;

class Restaurant : public Store
{
private:
	char*	foodType;

public:
	Restaurant(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a, const char* type);
	Restaurant(Restaurant &Restaurant) = delete;
	Restaurant(Restaurant && Restaurant) = delete;
	~Restaurant();

	const Restaurant&	operator=(const Restaurant& other) = delete;
	const Restaurant&	operator=(Restaurant&& other) = delete;

	const char*			getFoodType() const { return foodType; }
	void				setFoodType(const char* type);
	void				show(ostream& out) const;
	void				specialEvent() const;
};

