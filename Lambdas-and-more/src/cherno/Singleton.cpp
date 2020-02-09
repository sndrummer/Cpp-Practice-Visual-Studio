#include "Singleton.h"
namespace Cherno
{
	Singleton& Singleton::getInstance()
	{
		static Singleton instance;
		return instance;
	}
	
	bool Singleton::itsOver9000() const
	{
		return powerLevel > 9000;
	}
	
	void Singleton::powerUp()
	{
		powerLevel += 100;
	}


	int Singleton::getPowerLevel() const
	{
		return powerLevel;
	}
}
