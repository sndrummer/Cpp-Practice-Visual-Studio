#include "functionPointers.h"
#include <iostream>

//function pointers and lambdas
void helloWorld(int a)
{
	std::cout << "Hello World, value a: " << a << std::endl;
}

void simpleFunctionPointerExample()
{
	//The type is void
	void (*function1)(int) = helloWorld; //this is the type but better to use auto OR typedef
	auto function2 = helloWorld; //leave out the parenthesis to get function pointer

	typedef void (*HelloWorldFunction)(int); //Define the type of the function

	HelloWorldFunction function = helloWorld;
	std::cout << "Function is stored at: " << function << std::endl; //see memory address

	//Run the function
	function(8);
}

//Instead of using this you can use an anonymous function/lambda
void printValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

//Parameter is a function pointer so we are able to call the function passed in
void forEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

//main functionfunction pointers and anonymous functions
int runPointerExample()
{
	std::vector<int> values = { 1, 2, 3, 4, 5 };
	//forEach(values, printValue);

	/**
	 * This is an anonymous function,
	 * The square brackets are called a capture method, how you pass variables in from the outside world
	 */
	forEach(values, [](int value) {std::cout << "Value: " << value << std::endl; }); //this is the anonymous function version 
	return 0;
}
