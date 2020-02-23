#pragma once
#include "ISubject.h"
#include "WeatherType.h"
namespace Observer
{
	class Weather : public ISubject
	{
	public:
		explicit Weather(WeatherType currentType);
		void addObserver(IObserver* observer);
		void removeObserver(IObserver* observer);
		void removeObserver(WeatherType weather, IObserver* observer);
		void timePasses();
	private:
		WeatherType mCurrentWeather;
		typedef std::vector<WeatherType> WeatherTypeList;
		WeatherTypeList mWeatherTypes;
	};
}
