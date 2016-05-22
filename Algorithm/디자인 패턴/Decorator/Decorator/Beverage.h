#pragma once
#include <string>
#include <iostream>
using namespace std;
class CBeverage
{
	string description;
public:

	CBeverage() : description("Unknown Beverage")
	{
	}

	~CBeverage()
	{
	}
	CBeverage(string s) : description(s) {}

	virtual string getDescription() { return description; }
	virtual double cost() = 0;
};

