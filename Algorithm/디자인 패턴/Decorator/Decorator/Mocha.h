#pragma once
#include "CondimentDecorator.h"
#include <iostream>
#include <string>
using namespace std;
class CMocha : public CCondimentDecorator
{
	CBeverage *beverage;
public:

	CMocha()
	{
	}

	~CMocha()
	{
	}
	CMocha(CBeverage *b) : beverage(b) {}

	string getDescription() {
		return beverage->getDescription() += ", Mocha";
	}

	double cost() { return 0.20 + beverage->cost(); }
};

