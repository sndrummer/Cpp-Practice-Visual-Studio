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
#include "templates/Stack.h"

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


void testObserverPattern()
{
	// Test the observer pattern

	Observer::Weather weather(Observer::WeatherType::SUNNY);
	Observer::Orcs orcs;

	weather.addObserver(&orcs);

	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
	weather.timePasses();
}

// comment this out to disable memory allocation.
// #define TESTING_MEMORY_ALLOCATION

#ifdef TESTING_MEMORY_ALLOCATION

struct AllocationMetrics
{
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;

	uint32_t currentUsage() { return totalAllocated - totalFreed; };
};

static AllocationMetrics s_allocation_metrics;

void* operator new(size_t size)
{
	s_allocation_metrics.totalAllocated += size;
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	s_allocation_metrics.totalFreed += size;
	std::cout << "Freeing " << size << " bytes" << std::endl;
	free(memory);
}


static void printMemoryUsage()
{
	std::cout << "Memory usage " << s_allocation_metrics.currentUsage() << " bytes" << std::endl;
}

void testMemoryAllocation()
{
	// vectorPractice();
	printMemoryUsage();
	{
		std::string a = "Judy Judy Judy Judy Judy Judy Judy Judy Judy You do can't know Judy";
		printMemoryUsage();
	}
	printMemoryUsage();
}

#endif

// Explicit Stack<int> template
void testTemplates()
{
	using namespace Templates;
	IntStack myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);

	std::cout << "Here is the stack before the pop: " << myStack << std::endl;
	std::cout << "We are popping here is the value: " << myStack.pop() << std::endl;
	std::cout << "We are popping here is the value: " << myStack.pop() << std::endl;
	std::cout << "We are popping here is the value: " << myStack.pop() << std::endl;

	std::cout << "Here is the stack after: " << myStack << std::endl;
}


int main()
{
	testTemplates();
	return 0;
}
