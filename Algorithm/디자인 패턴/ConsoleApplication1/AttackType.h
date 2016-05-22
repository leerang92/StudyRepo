#pragma once
#include "Attack.h"
class CAttackType :
	public CAttack
{
public:

	CAttackType()
	{
	}

	~CAttackType()
	{
	}

	bool attack(int range) {
		if (range < 5)
			return 0;
		else
			return 1;

	}
};

