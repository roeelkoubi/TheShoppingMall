#pragma once
#include <iostream>
#include "MallExceptions.h"
using namespace std;

class Employee
{
protected:
	int			sSalary;
	char*		pName;
	static int	eID;
	int			iId;
	
public:
	Employee(const char* name, int salary);
	Employee(Employee& Employee) = delete; 
	Employee(Employee && Employee) = delete; 
	virtual ~Employee();

	const Employee& operator=(Employee&& other) = delete;
	const Employee& operator=(const Employee& other) = delete;

	char* const		getName() const { return pName;}
	int				getID() const { return eID; }
	int				getSalary() const { return sSalary; }
	void			setName(const char* name);
	void			setSalary(int salary_e);
	const Employee& operator>=(const Employee& other) const;
	const Employee& operator<=(const Employee& other) const;
	const Employee&	operator+(int add);
	virtual int		calculateSalary() const = 0;
	virtual void	show(ostream& out) const = 0;
};