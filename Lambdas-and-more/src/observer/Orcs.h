#pragma once
#include "WeatherObserver.h"

namespace Observer
{
	class Orcs : public WeatherObserver
	{
	public:
		virtual ~Orcs() = default;
		void update(int message) override;
	};
}
