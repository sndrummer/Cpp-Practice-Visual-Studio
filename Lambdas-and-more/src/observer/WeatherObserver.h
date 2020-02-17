#pragma once
#include "IObserver.h"

namespace Observer
{
	class WeatherObserver : public IObserver
	{
	public:
		void update(int message) override = 0;
	};

}

