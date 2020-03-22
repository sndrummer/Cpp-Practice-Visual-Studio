#pragma once

namespace Observer
{
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void update(int message) = 0;
};
}
