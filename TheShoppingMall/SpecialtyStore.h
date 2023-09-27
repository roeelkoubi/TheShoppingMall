#pragma once
#include <iostream>
#include "Store.h"
using namespace std;

class SpecialtyStore : public Store
{
private:
	char*	merchandiseType;

public:
	SpecialtyStore(const char* name, int clientListSize_a, int employeeListSize_a, int productListSize_a,const char* type);
	SpecialtyStore(SpecialtyStore& SpecialtyStore) = delete;
	SpecialtyStore(SpecialtyStore&& SpecialtyStore) = delete;
	~SpecialtyStore();

	const SpecialtyStore&	operator=(const SpecialtyStore& other) = delete;
	const SpecialtyStore&	operator=(SpecialtyStore&& other) = delete;

	const char*				getMerchandiseType() const { return merchandiseType; }
	void					setMerchandiseType(const char* type);
	void					show(ostream& out) const;
	void					specialEvent() const;
};