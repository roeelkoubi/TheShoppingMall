#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"
#include "MallExceptions.h"

class MallEmployee : public Employee
{
private:
	double	discountFee;
	int		bBonus; 

public:
	MallEmployee(const char* name, int salary, double discount,int bonus);

	double	getDiscountFee() const { return discountFee;}
	void	setBonus(int bonus);
	void	setDiscountFee(double fee);
	int		calculateSalary() const override;
	void	show(ostream& out) const override;
};

