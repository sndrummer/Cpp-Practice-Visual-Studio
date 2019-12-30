#include "functionPointers.h"
#include "parameterPacks.h"
#include "lambdas.h"
#include "FileWriter.h"
#include "const_pointers.h"
#include "maps.h"
#include "vectors.h"
#include "lists.h"

int main()
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
	return 0;
}
