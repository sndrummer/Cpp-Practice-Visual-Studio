#pragma once
#include "IObserver.h"
#include <map>
#include <set>
#include <string>

namespace Observer
{
	class ISubject
	{
	public:
		virtual ~ISubject() = default;

		/// Add a new observer to the list of observers
		virtual void subscribe(int message, IObserver* observer);

		/// Remove an observer from the list of observers 
		virtual void unsubscribe(int message, IObserver* observer);

		/// call the update method of all subscribed observers
		virtual void notify(int message);

	private:
		typedef std::set<IObserver*> ObserverSet;
		typedef std::map<int, ObserverSet> ObserverMap;
		ObserverMap mObservers;
	};
}
