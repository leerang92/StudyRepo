#pragma once
#include "CondimentDecorator.h"
#include <iostream>
#include <string>
using namespace std;
class CMilk : public CCondimentDecorator
{
	CBeverage *beverage;
public:

	CMilk()
	{
	}

	~CMilk()
	{
	}
	CMilk(CBeverage *b) :beverage(b) {}

	string getDescription() {
		return beverage->getDescription() += ", Milk";
	}

	double cost() { return 0.10 + beverage->cost(); }
};

