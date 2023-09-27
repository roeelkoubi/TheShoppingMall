#include "ShoppingMallManager.h"

const int ShoppingMallManager::STR = 255;
int ShoppingMallManager::usersCount = 0;
ShoppingMallManager* ShoppingMallManager::manager = nullptr;

ShoppingMallManager::ShoppingMallManager() 
{
	theMall = createShoppingMall();
    hardCoded();
}

ShoppingMallManager::~ShoppingMallManager()
{
	if (theMall)
		delete theMall;
}

ShoppingMallManager* ShoppingMallManager::getManagerInstance()
{
	if (manager == nullptr)
		manager = new ShoppingMallManager();
	
	usersCount++;
	return manager;
}

void ShoppingMallManager::releaseManagerInstance()
{
	usersCount--;
	if (usersCount == 0)
	{
		delete manager;
		manager = nullptr;
	}
}

ShoppingMall* ShoppingMallManager::createShoppingMall()
{
    cout << "------ Welcome To the Shooping Mall ------ " << endl;
    cout << endl;
    cout << "--> Please enter Shopping Mall name:\n";
    char name[STR];
    cin.getline(name, STR);
    cout << "--> Please enter city name:\n";
    char cName[STR];
    cin.getline(cName, STR);

    cout << "--> Please enter street name:\n";
    char street[STR];
    cin.getline(street, STR);

    int houseNum = getIntFromUser("house number", 1, 100);
    Address add(cName, street, houseNum);

    int employeeListSize = getIntFromUser("Employee list size", 11, 30);
    int storeListSize = getIntFromUser("Store list size", 7, 30);
    return new ShoppingMall(name, add, employeeListSize, storeListSize);
}

void ShoppingMallManager::createStore()
{
    cout << "--------------------------------" << endl;
    cout << "Please select type of store:\n1.Restaurant\n2.Entertainment\n3.Specialty" << endl;
    int selection = getIntFromUser("your selection", 1, 3);
    cout << "--------------------------------" << endl;
    switch (selection) {
    case eRestaurant:
        if (!theMall->addStore(StoreFactory::createStore(eRestaurant)))
            throw ListIsFullException("Store list");
        break;
    case eEntertainment:
        if (!theMall->addStore(StoreFactory::createStore(eEntertainment)))
            throw ListIsFullException("Store list");
        break;
    case eSpecialty:
        if (!theMall->addStore(StoreFactory::createStore(eSpecialty)))
            throw ListIsFullException("Store list");
        break;
    default:
        return;
    }
}

void ShoppingMallManager::createEmployee()
{
    cout << "--------------------------------" << endl;
    cout << "Please select type of Employee:\n1.Store employee\n2.Mall employee\n3.Maintenance employee\n4.Store-Maintenance employee\n";
    int selection = getIntFromUser("your selection", 1, 4);
    cout << "--------------------------------" << endl;
    switch (selection) {
    case eStoreEmployee:
    {
        if (theMall->getStoreCounter() < 1)
            throw GeneralException("ERROR - Need to create stores before creating Store employees.");

        cout << "Please select the store you wish to add the employee to:\n";
        cout << endl;
        theMall->showAllStores();
        int sSelection = getIntFromUser("your selection", 1, theMall->getStoreCounter());
        cout << "--------------------------------" << endl;
        Store* sTemp = theMall->getStoreByIndex(sSelection - 1);
        StoreEmployee* emp = dynamic_cast<StoreEmployee*>(EmployeeFactory::createEmployee(eStoreEmployee, sTemp));
        if (!sTemp->addEmployee(emp))
            throw ListIsFullException("Employee list");
        break;
    }
    case eMallEmployee:
        if (!theMall->addEmployee(EmployeeFactory::createEmployee(eMallEmployee)))
            throw ListIsFullException("Employee list");
        break;
    case eMaintenanceEmployee:
        if (!theMall->addEmployee(EmployeeFactory::createEmployee(eMaintenanceEmployee)))
            throw ListIsFullException("Employee list");
        break;
    case eStoreMaintenanceEmployee:
    {
        if (theMall->getStoreCounter() < 1)
            throw GeneralException("ERROR - Need to create stores before creating Store-Maintenance employees.");

        cout << "Please select the store you wish to add the employee to\n";
        cout << endl;
        theMall->showAllStores();
        int sSelection = getIntFromUser("your selection", 1, theMall->getStoreCounter());
        cout << "--------------------------------" << endl;
        Store* sTemp = theMall->getStoreByIndex(sSelection - 1);
        StoreMaintenanceEmployee* emp = dynamic_cast<StoreMaintenanceEmployee*>(EmployeeFactory::createEmployee(eStoreMaintenanceEmployee, sTemp));
        if (!sTemp->addEmployee(emp))
            throw ListIsFullException("Employee list");
        break;
    }
    default:
        return;
    }
}

void ShoppingMallManager::createProduct(Store* sto)
{
    cout << "--> Please enter Product name:\n";
    char name[STR];
    cleanBuffer();
    cin.getline(name, STR);
    bool loop = true;
    int id;
    while (loop) {
        id = getIntFromUser("product ID, a number", 1, 1000);
        if (sto->checkPID(id))
            loop = false;
    }
    int price = getIntFromUser("product price, a number", 1, 1000);
    if (!sto->addProduct(new Product(name, id, price)))
        throw ListIsFullException("Product list");
}

void ShoppingMallManager::createClient()
{
    if (theMall->getStoreCounter() < 1)
        throw GeneralException("ERROR - Need to create at least one store before creating clients.");

    cout << "--------------------------------" << endl;
    cout << "Please select the store you wish to add the client to\n";
    theMall->showAllStores();
    int sSelection = getIntFromUser("your selection", 1, theMall->getStoreCounter());
    cout << "--------------------------------" << endl;
    Store* sTemp = theMall->getStoreByIndex(sSelection - 1);
    cout << "--> Please enter Client name:\n";
    char name[STR];
    cleanBuffer();
    cin.getline(name, STR);
    cout << "--> Please enter Client ID number:\n";
    char id[STR];
    cin.getline(id, STR);
    int budget = getIntFromUser("Client budget", 1, 100000);
    cout << "--> Please enter city name:\n";
    cleanBuffer();
    char cName[STR];
    cin.getline(cName, STR);
    cout << "--> Please enter street name:\n";
    char street[STR];
    cin.getline(street, STR);

    int houseNum = getIntFromUser("house number", 1, 999);
    cout << "--------------------------------" << endl;
    Address add(cName, street, houseNum);

    if (!sTemp->addClient(new Client(name, id, budget, add)))
        throw ListIsFullException("Client List");
}

void ShoppingMallManager::showMallEmployees()
{
    cout << "--------------------------------" << endl;
    theMall->showAllEmployees();
}

void ShoppingMallManager::showMallStores()
{
    cout << "--------------------------------" << endl;
    theMall->showAllStores();
}

void ShoppingMallManager::showMall()
{
    cout << "--------------------------------" << endl;
    theMall->show(cout);
}

void ShoppingMallManager::selectStoreMenu()
{
    if (theMall->getStoreCounter() < 1)
        throw GeneralException("ERROR - Need to create at least one store before selecting store menu.");

    bool loop = true;
    do {
        cout << "--------------------------------" << endl;
        cout << "--> Please select a store:" << endl;
        cout << endl;
        theMall->showAllStores();
        cout << endl;
        int sSelection = getIntFromUser("your selection", 1, theMall->getStoreCounter());
        cout << "--------------------------------" << endl;
        Store* sTemp = theMall->getStoreByIndex(sSelection - 1);
        cout << "Please select store action:\n0.Exit to main menu\n1.Create new Product\n2.Show Store Employees\n3.Show Store Products\n";
        cout << "4.Show Store Clients\n5.Make maintenance call\n6.Initiate special event\n7.Client Buy Item" << endl;
        int selection = getIntFromUser("your selection", 0, 7);
        cout << "--------------------------------" << endl;
        switch (selection) {
        case 1:
            createProduct(sTemp);
            break;
        case 2:
            sTemp->showAllEmployeesInStore();
            break;
        case 3:
            sTemp->showAllProducts();
            break;
        case 4:
            sTemp->showAllClients(false);
            break;
        case 5:
            cout << "--> Please enter maintenance type:\n";
            char type[STR];
            cleanBuffer();
            cin.getline(type, STR);
            theMall->maintenanceCallAlert(sTemp, type);
            break;
        case 6:
            sTemp->specialEvent();
            break;
        case 7:
        {
            if (sTemp->getClientListSize() == 0) {
                cout << "There are no clients in " << sTemp->getName() << endl;
                break;
            }
            cout << "--> Please select a client:" << endl;
            sTemp->showAllClients(true);
            int cIndex = getIntFromUser("client index", 1, sTemp->getClientListSize());
            cout << "Please select a product to purachse:" << endl;
            sTemp->showAllProducts();
            int pIndex = getIntFromUser("item index", 1, sTemp->getNumOfProducts());
            if (!sTemp->clientBuyProduct(cIndex - 1, pIndex - 1))
                cout << "Buy product failed - Client does not have enough money for this product." << endl;
            else
                cout << "Thank you for your purchase!" << endl;
            break;
        }
        default:
            loop = false;
            cout << "Exiting to main menu" << endl;
        }
    } while (loop);
}

void ShoppingMallManager::hardCoded()
{
    Restaurant* s1 = new Restaurant("Cafe Cafe", 25, 10, 10, "Diray");
    Entertainment* s2 = new Entertainment("cinema city", 25, 10, 10, "Movies");
    SpecialtyStore* s3 = new SpecialtyStore("Columbia", 20, 10, 100, "Traveling Equipment");

    theMall->addStore(s1);
    theMall->addStore(s2);
    theMall->addStore(s3);

    Restaurant* s4 = new Restaurant("Cafe Doga", 10, 20, 10, "Coffe Place");
    Entertainment* s5 = new Entertainment("Mini Golf", 25, 15, 2, "Golf");
    SpecialtyStore* s6 = new SpecialtyStore("WeShoes", 20, 10, 70, "Shoes");

    theMall->addStore(s4);
    theMall->addStore(s5);
    theMall->addStore(s6);

    MallEmployee* e1 = new MallEmployee("Dani", 5500, 0.3, 20);
    MallEmployee* e2 = new MallEmployee("Roee", 9000, 0.1, 30);

    theMall->addEmployee(e1);
    theMall->addEmployee(e2);

    StoreEmployee* e3 = new StoreEmployee("Morgan", 2000, s5);
    StoreEmployee* e4 = new StoreEmployee("Elad", 8000, s6);
    StoreEmployee* e5 = new StoreEmployee("Moran", 9000, s4);

    s1->addEmployee(e3);
    s2->addEmployee(e4);
    s3->addEmployee(e5);

    MaintenanceEmployee* e6 = new MaintenanceEmployee("Dor", 4000, 100);
    MaintenanceEmployee* e7 = new MaintenanceEmployee("Moshe", 5000, 700);

    theMall->addEmployee(e6);
    theMall->addEmployee(e7);

    Product* p1 = new Product("Gloves", 1, 150);
    Product* p2 = new Product("Softshell jacket", 2, 500);

    s3->addProduct(p1);
    s3->addProduct(p2);

    Product* p3 = new Product("Titanic", 3, 25);
    Product* p4 = new Product("Need For Speed 5 - 3D", 4, 50);

    s2->addProduct(p3);
    s2->addProduct(p4);

    Product* p5 = new Product("Nike Shoes", 1, 150);
    Product* p6 = new Product("Adidas Shoes", 1, 150);

    s6->addProduct(p5);
    s6->addProduct(p6);

    Product* p7 = new Product("Coffe", 6, 15);
    Product* p8 = new Product("Cookie", 7, 25);

    s1->addProduct(p7);
    s1->addProduct(p8);

    StoreMaintenanceEmployee* em1 = new StoreMaintenanceEmployee("dani", 1000, s1, 50, 0.2, 1);
    StoreMaintenanceEmployee* em2 = new StoreMaintenanceEmployee("amir", 2000, s2, 40, 0.3, 2);
    StoreMaintenanceEmployee* em3 = new StoreMaintenanceEmployee("roee", 50, s3, 20, 0.2, 1);

    s1->addEmployee(em1);
    s2->addEmployee(em2);
    s3->addEmployee(em3);

    Address ad1("New York", "FIFTH AVNUE", 20);
    Address ad2("Boston", "Road", 10);

    Client* c1 = new Client("danidin", "20788923", 400, ad1);
    Client* c2 = new Client("Yakov", "20734723", 300, ad2);

    s1->addClient(c1);
    s2->addClient(c2);
}
