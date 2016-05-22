#pragma once
#include "LongAttack.h"
#include "ShortAttack.h"
class CAttack
{
	CLongAttack *m_lonAttack;
	CShortAttack *m_shoAttack;

public:

	CAttack()
	{}
	~CAttack()
	{
	}

	void ShowLongAttack() { m_lonAttack->longAttack(); }
	void ShowShotAttack() { m_shoAttack->shotAttack(); }
	void setLongAttack(CLongAttack *lAttack) { m_lonAttack = lAttack; }
	void setShotAttack(CShortAttack *sAttack) { m_shoAttack = sAttack; }
	virtual bool attack(int range) = 0;
};

