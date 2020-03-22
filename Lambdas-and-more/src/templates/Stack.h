#pragma once
#include <vector>
#include <string>
#include <ostream>


/**
 * Here is an explicit instantiation, meaning that you can only instantiate certain types that will be defined in the cpp file
 * If you are doing implicit instantiation then you will have to provide implementations in the header file
 * This way you can seperate them in the .cpp file
 */
namespace Templates
{
template <typename T>
class Stack //notice that you do not add the <> to the class definition
{
public:
	void push(T val);
	T pop();

	bool isEmpty() const;
	std::string toString() const;

private:
	std::vector<T> mStack;
};


// this is to indicate to the user the different stacks that are available to use
typedef Stack<int> IntStack;
typedef Stack<double> DoubleStack;
typedef Stack<std::string> StringStack;


/**
 * This is the proper way to do ostream, make it outside of the class definition and have it access a public toString method!!!!!
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
	return os << stack.toString();
}
}
