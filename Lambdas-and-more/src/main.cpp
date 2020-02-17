#include "functionPointers.h"
#include "parameterPacks.h"
#include "lambdas.h"
#include "FileWriter.h"
#include "const_pointers.h"
#include "maps.h"
#include "vectors.h"
#include "lists.h"
#include "Callback/Callback.h"
#include "cherno/local_static.h"
#include "cherno/Singleton.h"
#include  "observer/Orcs.h"
#include "observer/Weather.h"

//void (*CallbackType) (const std::string& name, void* data);

void static helloWorldFunc(const std::string& name, void* data)
{
	const auto pd = static_cast<int*>(data);
	std::cout << "Here is the name: " << name << ", and here is the data: " << *pd << std::endl;
}

void tests()
{
	// FileWriter fw("example.txt");
	// std::thread t1(&FileWriter::writeToFile, &fw, "Hello Butt"); //it needs a pointer to fw so you can call new and pass it in as well
	// std::thread t2(&FileWriter::writeToFile, &fw, "This is the second message");
	//
	// t1.join();
	// t2.join();
	//
	//testConstPointers();
	// testOrderedMap();
	// testUnorderedMap();

	// vectorPractice();


	practiceLists();

	Callback callback;
	int a = 4;
	callback.setCallback(helloWorldFunc, &a);

	callback.invokeCallback();

	Cherno::Function();
	Cherno::Function();
	Cherno::Function();
	Cherno::Function();
	Cherno::Function();


	// note that boolalpha will print true and false
	Cherno::Singleton& instance = Cherno::Singleton::getInstance();
	bool over9000 = instance.itsOver9000();
	std::cout << std::boolalpha << "Over 9000? " << over9000 << std::endl;


	instance.powerUp();
	over9000 = instance.itsOver9000();
	std::cout << std::noboolalpha << "Over 9000 after power up? " << over9000 << std::endl;
}

using namespace Observer;
int main()
{
	// Test the observer pattern

	Weather weather(WeatherType::SUNNY);
	Orcs orcs;

	weather.addObserver(&orcs);

	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	
	
	return 0;
}
