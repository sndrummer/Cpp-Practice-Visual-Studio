#include "lambdas.h"
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm> //use for find_if 


//Parameter is a function pointer so we are able to call the function passed in
static void forEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
	{
		func(value);
	}
}

//remember that the order for the lambda expression is captures, params, then the function
int runLambdaTest()
{
	std::vector<int> values = { 1, 5, 1, 1, 4 };
	const auto greaterThanThreeLambda = [](const int value) { return value > 3; };
	
	for (auto it = std::find_if(values.begin(),
	                            values.end(),
	                            greaterThanThreeLambda);
	     it != values.end();
	     it = std::find_if(std::next(it), values.end(), greaterThanThreeLambda))
	{
		std::cout << "Value greater than 3: " << *it << std::endl;
	}

	int a = 6;
	// '=' captures all outside passes by copy or value, use & to pass by reference
	const auto lambda2 = [=](const int value) { std::cout << "Value: " << a << std::endl; };

	forEach(values, lambda2);
	return 0;
}
