#include "Subject.h"
#include "DisplayElement.h"
#include "Observer.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "statisticDisplay.h"
#include "forecastDisplay.h"
using namespace std;

void main() {

	CWeatherData *weatherData = new CWeatherData();
	CCurrentConditionDisplay *currentDisplay = new CCurrentConditionDisplay(weatherData);
	forecastDisplay *forecastDisplays = new forecastDisplay(weatherData);
	statisticDisplay *statisticDisplays = new statisticDisplay(weatherData);

	weatherData->setMeasurements(80, 65, 30);
	weatherData->setMeasurements(70, 60, 28);
	weatherData->setMeasurements(75, 50, 25);
	weatherData->setMeasurements(10, 10, 10);

}