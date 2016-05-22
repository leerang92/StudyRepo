#pragma once
#include "Beverage.h"
class CCondimentDecorator : public CBeverage
{
public:

	CCondimentDecorator()
	{
	}

	~CCondimentDecorator()
	{
	}

	virtual string getDescription() = 0;
};

