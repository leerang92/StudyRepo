#pragma once
#include<iostream>
#include "DisplayElement.h"
#include "Observer.h"
using namespace std;

class statisticDisplay : public CDisplayElement, public CObserver
{
	int temperature;
	int humidity;
	int avg;
	int max, min;
	CSubject *weatherData;
public:

	statisticDisplay()
	{
		max = 0;
		min = 0;
		avg = 0;
	}

	~statisticDisplay()
	{
	}

	statisticDisplay(CSubject *wData) {
		weatherData = wData;
		weatherData->registerObsever(this);
	}

	void update(int temp, int hum, int press) {
		temperature = temp;
		humidity = hum;
		display();
	}

	void display() {
		avg = (temperature + humidity) / 2;
		max = temperature > humidity ? temperature : humidity;
		min = temperature < humidity ? temperature : humidity;

		cout << "Avg/Max/Min : " << avg << "/" << max << "/" << min << endl;
	}
};

