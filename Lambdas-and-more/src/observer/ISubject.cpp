#include "ISubject.h"

namespace Observer
{
	void ISubject::subscribe(const int message, IObserver* observer)
	{
		if (observer == nullptr) return;

		const auto it = mObservers.find(message);
		if (it == mObservers.end())
		{
			// create new Set
			mObservers[message] = ObserverSet();
		}

		// add observer to the set
		mObservers[message].emplace(observer);

	}

	void ISubject::unsubscribe(const int message, IObserver* observer)
	{
		if (observer == nullptr || mObservers.find(message) == mObservers.end()) return;

		auto observers = mObservers[message];
		observers.erase(observer);

	}

	void ISubject::notify(const int message)
	{
		auto observers = mObservers[message];
		for (auto observer : observers)
		{
			observer->update(message);
		}
	}

}

