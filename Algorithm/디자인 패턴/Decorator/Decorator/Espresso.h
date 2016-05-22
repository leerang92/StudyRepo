#pragma once
#include "Beverage.h"
class CEspresso : public CBeverage
{
public:

	CEspresso() : CBeverage("Espresso")
	{
	}

	~CEspresso()
	{
	}

	double cost() { return 1.99; }
};

