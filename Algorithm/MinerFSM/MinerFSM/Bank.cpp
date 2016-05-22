#include "Bank.h"

CBank::CBank()
{
}
CBank::~CBank()
{
}

CBank * CBank::getInstance()
{
	static CBank instance;
	return &instance;
}
#include "MinerAI.h"
#include "Location.h"
#include "Mine.h"
#include "Home.h"
#include <iostream>
using namespace std;
void CBank::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != BANK) {
		cout << pMiner->getName() << " : 은행으로 갑니다.." << endl;
		pMiner->changeLocation(BANK);
	}
}

void CBank::Execute(CMinerAI * pMiner)
{
	pMiner->addWealth(pMiner->getGold());
	pMiner->setGoldCarried(0);
	cout << pMiner->getName() << " : 금을 저금했습니다.. " << endl;
	cout << pMiner->getName() << " : 총 저금한 금액 : " << pMiner->getMoney() << endl;

	if (pMiner->isRich()) {
		cout << pMiner->getName() << " : 저금을 많이 했군... 집에서 쉬자.." << endl;
		pMiner->changeState(CHome::getInstance());
	}
	else {
		cout << pMiner->getName() << " : 돈이 부족해... 금을 더 캐야해.." << endl;
		pMiner->changeState(CMine::getInstance());
	}
}

void CBank::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : 은행을 떠납니다.." << endl;
}
