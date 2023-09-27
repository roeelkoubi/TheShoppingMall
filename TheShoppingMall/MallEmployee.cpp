#include "MallEmployee.h"

MallEmployee::MallEmployee(const char* name, int salary, double discount,int bonus):
	Employee(name,salary), discountFee(discount), bBonus(bonus)
{}

void MallEmployee::setDiscountFee(double fee)
{
    if (fee > 0 && fee < 1)
        discountFee = fee;
    else
        throw GeneralException("Invalid discount fee. Please provide a value between 0 and 1");
}

void MallEmployee::setBonus(int bonus)
{
    if (bonus < 0)
        throw GeneralException("Bonus cannot be negative value\n");

    bBonus = bonus;
}

int MallEmployee::calculateSalary() const 
{
    int newSalary = sSalary + bBonus;
    return newSalary;

}

void MallEmployee::show(ostream& out) const
{
    if ((pName == nullptr))
        out << "Error in Mall Employee information" << endl;
    else
        out << "[" << pName << " earn " << sSalary << ", and had discount of " << discountFee << " made bonus of " << bBonus << "]" << endl;
}
