#pragma once
#include <vector>

namespace Observer
{
	enum class WeatherType
	{
		SUNNY,
		CLOUDY,
		RAINY,
		SNOWY,
		STORM
	};


	static std::vector<WeatherType> getWeatherTypesAsList()
	{
		std::vector<WeatherType> weathers;
		weathers.push_back(WeatherType::SUNNY);
		weathers.push_back(WeatherType::CLOUDY);
		weathers.push_back(WeatherType::RAINY);
		weathers.push_back(WeatherType::SNOWY);
		weathers.push_back(WeatherType::STORM);

		return weathers;
	}
}
