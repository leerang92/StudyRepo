#pragma once
#include "PizzaStore.h"
#include "CKStyleCheesePizza.h"

class CCKPizzaStore : public CPizzaStore
{
public:

	CCKPizzaStore()
	{
	}

	~CCKPizzaStore()
	{
	}

	CPizza *createPizza(string item) {
		if (item == "cheese")
			return new CCKStyleCheesePizza();
	}
};

