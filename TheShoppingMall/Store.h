#pragma once
#include <iostream>
#include "StoreEmployee.h"
#include "Product.h"
#include "Client.h"
#include "MallExceptions.h"
using namespace std;

class Client;
class Product;
class StoreEmployee;

class Store
{
protected:
	char*				pName;
	int					clientListSize;
	int					employeeListSize;
	int					productListSize;
	int					numOfClients = 0;
	int					numOfEmployes = 0;
	int					numOfProducts = 0;
	Client**			clientList;
	StoreEmployee**		employeeList;
	Product**			productList;

public:
	Store(const char* name,int clientListSize_a, int employeeListSize_a, int productListSize_a);
	Store(Store& store) = delete;
	Store(Store&& store) = delete;
	virtual ~Store();

	const Store&	operator=(const Store& other) = delete;
	const Store&	operator=(Store&& other) = delete;

	const char*		getName() const { return pName; }
	int				getNumOfClient() const { return numOfClients; }
	int				getNumOfEmployes() const { return numOfEmployes; }
	int				getNumOfProducts() const { return numOfProducts; }
	int				getClientListSize() const { return clientListSize; }
	int				getEmployeeListSize() const { return employeeListSize; }
	int				getProductListSize() const { return productListSize; }
	StoreEmployee** getEmployeeList() const { return employeeList; }
	Product**		getProductList() const { return productList; }
	Client** 		getClientList() const { return clientList; }
	bool			addProduct(Product* prod);
	bool			checkPID(int id);
	void			showAllEmployeesInStore() const;
	void			showAllProducts() const;
	void			showAllClients(bool nameOnly) const;
	bool			addClient(Client* client);
	void			setName(const char* name);
	bool			addEmployee(StoreEmployee* emp);
	bool			clientBuyProduct(int client, int product);
	virtual void	show(ostream& out) const = 0;
	virtual void	specialEvent() const = 0;
};

