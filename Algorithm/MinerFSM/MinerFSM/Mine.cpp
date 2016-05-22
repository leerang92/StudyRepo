#include "Mine.h"


CMine::CMine()
{
}

CMine::~CMine()
{
}

CMine * CMine::getInstance()
{
	static CMine instance;
	return &instance;
}

#include "MinerAI.h"
#include <iostream>
using namespace std;

void CMine::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != MINE) {
		cout << pMiner->getName() << " : 금광으로 걸어갑니다.." << endl;
		pMiner->changeLocation(MINE);
	}
}
#include "Bank.h"
#include "Saloon.h"
void CMine::Execute(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : 금을 캐고 있습니다.." << endl;
	cout << pMiner->getName() << " : 영차영차 " << endl;
	pMiner->addGold(1);
	pMiner->increaseFatigue();

	if (pMiner->isPoketFull()) {
		cout << pMiner->getName() << " : 금을 많이 캤군..." << endl;
		pMiner->changeState(CBank::getInstance());
	}
	if (pMiner->isThirsty()) {
		cout << pMiner->getName() << " : 힘들다..." << endl;
		cout << pMiner->getName() << " : 목이 마르다.." << endl;
		cout << pMiner->getGold() << " : 술집에 가서 한잔 해야겠다.." << endl;
		pMiner->changeState(CSaloon::getInstance());
	}
}

void CMine::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : 금광을 떠납니다.." << endl;
}
