#pragma once
#include "State.h"
class CHome :
	public CState
{
	CHome();
public:
	~CHome();
	static CHome *getInstance();
	void Enter(CMinerAI *);
	void Execute(CMinerAI *);
	void Exit(CMinerAI *);
};

