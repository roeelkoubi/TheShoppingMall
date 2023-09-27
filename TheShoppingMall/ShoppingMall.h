#pragma once
#include <iostream>
#include <ctime>
#include "Address.h"
#include "Store.h"
#include "MaintenanceEmployee.h"
#include "Employee.h"
#include "MallExceptions.h"
using namespace std;

class Store;

class ShoppingMall
{

private:

	char*		pName;
	Address		aAddress;
	Store**		storeList;
	Employee**	employeeList;  
	int			storeCounter = 0;
	int			employeeCounter = 0;
	int			employeeListSize;
	int			storeListSize;

public:
	ShoppingMall(const char* name, Address& add, int employeeLSize, int storeLSize);
	ShoppingMall(ShoppingMall& shoppingMall) = delete;
	ShoppingMall(ShoppingMall&& shoppingMall) = delete;
	~ShoppingMall();

	const ShoppingMall&		operator=(const ShoppingMall& other) = delete;
	const ShoppingMall&		operator=(ShoppingMall&& other) = delete;

	const char*				getName() const { return pName; } 
	const Address			getAddress() const { return aAddress; }
	Store**					getStoreList() const { return storeList; }
	int						getStoreCounter() const { return storeCounter; }
	int						getemployeeCounter() const { return employeeCounter; }
	void					showAllStores() const;
	void					showAllEmployees() const;
	Store*					getStoreByIndex(int index) const { return storeList[index]; }
	void					maintenanceCallAlert(Store* sTemp, char* type);
	void					setName(const char* name);
	bool					addStore(Store* store);
	bool					addEmployee(Employee* emp);
	void					show(ostream& out) const;
};