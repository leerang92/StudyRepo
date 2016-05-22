#pragma once
#include "CondimentDecorator.h"
#include <iostream>
#include <string>
using namespace std;
class CCosy : public CCondimentDecorator
{
	CBeverage *beverage;
public:

	CCosy()
	{
	}

	~CCosy()
	{
	}
	CCosy(CBeverage *b) :beverage(b) {}

	string getDescription() {
		return beverage->getDescription() += ", Mocha";
	}

	double cost() { return 0.30 + beverage->cost(); }
};

