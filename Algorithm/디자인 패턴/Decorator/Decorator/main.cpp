#include "Espresso.h"
#include "HouseBlend.h"
#include "Mocha.h"
#include "Milk.h"
#include "Cosy.h"
#include <iostream>
using namespace std;

void main()
{
	CBeverage *beverage = new CEspresso();
	cout << beverage->getDescription() << " $" << beverage->cost() << endl;

	CBeverage *beverage2 = new CHouseBlend();
	beverage2 = new CMocha(beverage2);
	beverage2 = new CMilk(beverage2);
	beverage2 = new CCosy(beverage2);

	cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

}