#pragma once
#include <iostream>
#include "Store.h"
using namespace std;

class Entertainment : public Store
{
private:
	char*	pEntertainmentType;

public:
	Entertainment(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a, const char* entertainmentType);
	Entertainment(Entertainment &entertainment) = delete;
	Entertainment(Entertainment && entertainment) = delete;
	~Entertainment();

	const Entertainment&	operator=(const Entertainment& other) = delete;
	const Entertainment&	operator=(Entertainment&& other) = delete;
	char*					getEntertainmentType() const { return pEntertainmentType; }
	void					setEntertainmentType(const char* type);
	void					show(ostream& out) const;
	void					specialEvent() const;
};

