#pragma once
#include "State.h"
class CSaloon :
	public CState
{
	CSaloon();
public:
	~CSaloon();
	static CSaloon *getInstance();
	void Enter(CMinerAI *pMiner);
	void Execute(CMinerAI *pMiner);
	void Exit(CMinerAI *pMiner);
};

