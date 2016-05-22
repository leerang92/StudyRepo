#pragma once
#include <list>
#include "Subject.h"
using namespace std;

class CWeatherData : public CSubject
{
	list<CObserver> obsevers;
	int temperature;
	int humidity;
	int pressure;

public:

	CWeatherData()
	{
	}

	~CWeatherData()
	{
	}

	int getTemperature() { return temperature; }
	int getHumidity() { return humidity; }
	int getPressure() { return pressure; };
	void registerObsever(CObserver *o) { obsevers.push_back(*o); }
	void removeObserver(CObserver *o) { obsevers.remove(*o); }

	void notifyObservers() {
		list<CObserver>::iterator itr = obsevers.front;
		//for (int i = 0; i < obsevers.size(); i++) {
		//	obsevers.front().update;
		//	//CObserver *ob;
		//	//ob->update(temperature, humidity, pressure);
		//}
		CObserver *ob = itr->update;
		ob->update(temperature, humidity, pressure);
	}

	void measurementChanged() {
		notifyObservers();
	}

	void setMeasurements(int temp, int hum, int press) {
		temperature = temp;
		humidity = hum;
		pressure = press;
		measurementChanged();
	}
};

