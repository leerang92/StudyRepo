#pragma once
#include "ShortAttack.h"
#include <iostream>
using namespace std;

class CSwordAttack :
	public CShortAttack
{
public:

	CSwordAttack()
	{
	}

	~CSwordAttack()
	{
	}

	void shotAttack() { cout << "Į!!" << endl; }
};

