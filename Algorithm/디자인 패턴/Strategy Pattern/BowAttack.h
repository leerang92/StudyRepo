#pragma once
#include "LongAttack.h"
#include <iostream>
using namespace std;

class CBowAttack :
	public CLongAttack
{
public:

	CBowAttack()
	{
	}

	~CBowAttack()
	{
	}
	void longAttack() { cout << "Ȱ" << endl; }
};

