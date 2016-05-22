#pragma once
#include "Pizza.h"
class CPizzaStore : public CPizza
{
public:

	CPizzaStore()
	{
	}

	~CPizzaStore()
	{
	}

	CPizza *orderPizza(string type) {
		CPizza *pizza = createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}

	virtual CPizza *createPizza(string type) = 0;
};

