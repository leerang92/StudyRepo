#pragma once
#include<iostream>
#include "DisplayElement.h"
#include "Observer.h"
using namespace std;

class forecastDisplay : public CDisplayElement, public CObserver
{
	int pressure;
	CSubject *weatherData;
public:

	forecastDisplay()
	{
	}

	~forecastDisplay()
	{
	}

	forecastDisplay(CSubject *wData) {
		weatherData = wData;
		weatherData->registerObsever(this);
	}

	void update(int temp, int hum, int press) {
		pressure = press;
		display();
	}

	void display() {
		if (pressure > 50)
			cout << "ranniy weather" << endl;
		else
			cout << "cool weather" << endl;
	}
};

