#include "Weather.h"
#include <iostream>

namespace Observer
{
	Weather::Weather(const WeatherType currentType)
		: mCurrentWeather(currentType),
		  mWeatherTypes(getWeatherTypesAsList())
	{
	}

	void Weather::addObserver(IObserver* observer)
	{
		for (auto weather : mWeatherTypes)
		{
			ISubject::subscribe(static_cast<int>(weather), observer);
		}
	}

	void Weather::removeObserver(IObserver* observer)
	{
		for (auto weather : mWeatherTypes)
		{
			ISubject::unsubscribe(static_cast<int>(weather), observer);
		}
	}

	void Weather::removeObserver(WeatherType weather, IObserver* observer)
	{
		ISubject::unsubscribe(static_cast<int>(weather), observer);
	}

	void Weather::timePasses()
	{
		const auto typeAsInt = static_cast<int>(mCurrentWeather);
		const auto nextWeatherType = (typeAsInt + 1) % static_cast<int>(mWeatherTypes.size());
		mCurrentWeather = static_cast<WeatherType>(nextWeatherType);
		
		std::cout << "Time passes and a new season comes..." << std::endl;
		notify(nextWeatherType);
	}

}
