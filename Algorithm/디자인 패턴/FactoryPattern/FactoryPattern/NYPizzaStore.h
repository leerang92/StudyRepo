#pragma once
#include "PizzaStore.h"
#include "NYStyleCheesePizza.h"
class CNYPizzaStore : public CPizzaStore
{
public:

	CNYPizzaStore()
	{
	}

	~CNYPizzaStore()
	{
	}

	CPizza *createPizza(string item) {
		if (item == "cheese")
			return new CNYStyleCheesePizza();
	}
};

