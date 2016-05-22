#pragma once
#include "Beverage.h"
class CHouseBlend : public CBeverage
{
public:

	CHouseBlend() : CBeverage("House Blend Coffee")
	{
	}

	~CHouseBlend()
	{
	}

	double cost() { return 0.89; }
};

