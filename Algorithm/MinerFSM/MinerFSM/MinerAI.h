#pragma once
#include "State.h"
#include "Home.h"
#include <string>

class CMinerAI
{
	CState *m_curState;
	int m_gold;
	int m_money;
	int m_fatigue;
	int m_rest;
	int m_location;
	int m_thirst;
	std::string m_name;
public:
	CMinerAI();
	~CMinerAI();
	CMinerAI(std::string name, CState *state) : m_name(name), m_curState(state),
		 m_gold(0), m_money(0), m_fatigue(0), m_rest(0), m_location(0), m_thirst(0) {}

	bool isPoketFull() { return m_gold >= kMaxNugget; }
	std::string getName() { return m_name; }
	int getLocation() { return m_location; }
	int getGold() { return m_gold; }
	int getMoney() { return m_money; }
	bool isFatigue() { return m_fatigue >= kMaxFatigue; }
	bool isThirsty() { return m_thirst >= kMaxThirst; }
	bool isRich() { return m_money >= kMaxMoney; }
	bool isRested() { return m_rest >= kMaxRest; }
	
	void addGold(int g) { m_gold += g; }
	void setGoldCarried(int g) { m_gold = g; }

	void increaseFatigue() { m_fatigue++; }
	void decreaseFatigue() { m_fatigue--; }
	void addWealth(int g) { m_money += g; if (m_money < 0) m_money = 0; }
	
	void drinkWhiskey() { m_thirst = 0; m_money -= 2; }

	void update();
	void changeState(CState *newState);
	void changeLocation(int newLocation) { m_location = newLocation; }
};

