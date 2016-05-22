#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class CPizza
{
	string name;
	string dourgh;
	string sauce;
	list<string> topping;
public:
	
	CPizza()
	{
	}

	~CPizza()
	{
	}
	CPizza(string pizzaName) {
		name = pizzaName;
	}

	void prepare() {
		cout << "Preparing " << name << endl;
		cout << "Tossing dough ... " << endl;
		cout << "Adding sauce..." << endl;
		cout << "Adding topping : ";
		list<string>::iterator itr;
		for (itr = topping.begin(); itr != topping.end(); itr++)
			cout << " " << *itr;
		cout << endl;
	}

	void bake() { cout << "Bake for 25 minutes at 350" << endl; }
	virtual void cut() { cout << "Cutting the pizza into diagonai slices" << endl; }
	void box() { cout << "Place pizza in official PizzaStore box" << endl; }

	string getName() {return name;}
};

