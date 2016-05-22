#pragma once
#include "State.h"
class CBank :
	public CState
{
	CBank();
public:
	~CBank();
	static CBank *getInstance();
	void Enter(CMinerAI *pMiner);
	void Execute(CMinerAI *pMiner);
	void Exit(CMinerAI *pMiner);
};

