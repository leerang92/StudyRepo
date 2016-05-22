#include "Saloon.h"

CSaloon::CSaloon()
{
}


CSaloon::~CSaloon()
{
}

CSaloon * CSaloon::getInstance()
{
	static CSaloon instance;
	return &instance;
}
#include "Location.h"
#include "MinerAI.h"
#include "Mine.h"
#include <iostream>
using namespace std;

void CSaloon::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != SALOON) {
		pMiner->changeLocation(SALOON);
		cout << pMiner->getName() << " : 술집으로 들어갑니다.." << endl;
	}
}

void CSaloon::Execute(CMinerAI * pMiner)
{
	if (pMiner->isThirsty()) {
		pMiner->drinkWhiskey();
		cout << pMiner->getName() << " : 술맛 좋다..." << endl;
		cout << pMiner->getName() << " : 잘 마셨다..." << endl;
		pMiner->changeState(CMine::getInstance());
	}
}

void CSaloon::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : 술집을 떠납니다.." << endl;
}
