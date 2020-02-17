#include "Orcs.h"
#include <iostream>
#include "WeatherType.h"

namespace Observer
{
	void Orcs::update(int message)
	{
		const auto weatherType = static_cast<WeatherType>(message);

		switch (weatherType)
		{
		case WeatherType::SUNNY:
			std::cout << "The sun hurts the orcs' eyes.";
			break;
		case WeatherType::CLOUDY:
			std::cout << "The orcs can't see the sky through the clouds";
			break;
		case WeatherType::RAINY:
			std::cout << "The orcs are drenched in the rain";
			break;
		case WeatherType::SNOWY:
			std::cout << "The orcs are freezing in the snow";
			break;
		case WeatherType::STORM:
			std::cout << "The storm causes the orcs to search for cover";
			break;
		default:
			std::cout << "Invalid type";
			break;
		}

		std::cout << std::endl;
	}

}
