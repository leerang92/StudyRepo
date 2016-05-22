#pragma once
#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"
#include <iostream>
using namespace std;

class CCurrentConditionDisplay : public CDisplayElement, public CObserver
{
	int temperature;
	int humidity;
	CSubject *weatherData;
public:

	CCurrentConditionDisplay()
	{
	}

	~CCurrentConditionDisplay()
	{
	}

	CCurrentConditionDisplay(CSubject *wData) {
		weatherData = wData;
		weatherData->registerObsever(this);
	}
	void update(int temp, int hum, int press) {
		temperature = temp;
		humidity = hum;
		display();
	}
	void display() {
		cout << "Current condition : " << temperature << "F degress and "
			<< humidity << "% humidity" << endl;
	}
};

