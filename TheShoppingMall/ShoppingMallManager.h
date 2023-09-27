#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "ShoppingMall.h"
#include "GeneralFunctions.h"
#include "Store.h"
#include "Product.h"
#include "StoreFactory.h"
#include "EmployeeFactory.h"
#include "MallExceptions.h"
using namespace std;

class ShoppingMallManager
{
private:
	ShoppingMall* theMall;
	static ShoppingMallManager*	manager;
	static int					usersCount;
	ShoppingMallManager();

public:
	static const int	STR;
	ShoppingMallManager(ShoppingMallManager& spmm) = delete;
	ShoppingMallManager(ShoppingMallManager&& spmm) = delete;
	~ShoppingMallManager();

	const ShoppingMallManager&		operator=(const ShoppingMallManager& spmm) = delete;
	const ShoppingMallManager&		operator=(ShoppingMallManager&& spmm) = delete;

	static ShoppingMallManager*		getManagerInstance();
	void							releaseManagerInstance();
	
	ShoppingMall*					createShoppingMall();
	void							createStore();
	void							createEmployee();
	void							createProduct(Store* sto);
	void							createClient();
	void							showMallEmployees();
	void							showMallStores();
	void							showMall();
	void							selectStoreMenu();
	void							hardCoded();
};