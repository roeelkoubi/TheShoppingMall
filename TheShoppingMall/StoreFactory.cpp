#include "StoreFactory.h"

const int StoreFactory::STR = 255;

Store* StoreFactory::createStore(int type)
{
    Store* pTemp = nullptr;
    cleanBuffer();
    switch (type)
    {
    case eRestaurant:
    {
        cout << "--> Please enter Restaurant name:\n";
        char name[STR];
        cin.getline(name, STR);

        int clientListSize = getIntFromUser("Client List Size", 1, 30);
        int employeeListSize = getIntFromUser("Employee List Size", 1, 30);
        int productListSize = getIntFromUser("Product List Size", 1, 30);

        cout << "--> Please enter food type:\n";
        char foodType[STR];
        cleanBuffer();
        cin.getline(foodType, STR);

        pTemp = new Restaurant(name, clientListSize, employeeListSize, productListSize, foodType);
        break;
    }
    case eEntertainment:
    {
        cout << "--> Please enter Entertainment store name:\n";
        char name[STR];
        cin.getline(name, STR);

        int clientListSize = getIntFromUser("Client List Size", 1, 30);
        int employeeListSize = getIntFromUser("Employee List Size", 1, 30);
        int productListSize = getIntFromUser("Product List Size", 1, 30);

        cout << "--> Please enter Entertainment type:\n";
        char entertainmentType[STR];
        cleanBuffer();
        cin.getline(entertainmentType, STR);
        pTemp = new Entertainment(name, clientListSize, employeeListSize, productListSize, entertainmentType);
        break;
    }
    case eSpecialty:
    {
        cout << "--> Please enter Specialty store name:\n";
        char name[STR];
        cin.getline(name, STR);

        int clientListSize = getIntFromUser("Client List Size", 1, 30);
        int employeeListSize = getIntFromUser("Employee List Size", 1, 30);
        int productListSize = getIntFromUser("Product List Size", 1, 30);

        cout << "--> Please enter merchandise type:\n";
        char merchandiseType[STR];
        cleanBuffer();
        cin.getline(merchandiseType, STR);
        pTemp = new SpecialtyStore(name, clientListSize, employeeListSize, productListSize, merchandiseType);
        break;
    }
    default:
        cout << "Store type does not exists." << endl;
        break;
    }
    return pTemp;
}