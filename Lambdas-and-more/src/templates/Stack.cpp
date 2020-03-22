#include "Stack.h"
#include <iostream>
#include <sstream>

/**
 * Note* you need the template typename declaration above all of these
 */
namespace Templates
{
template <typename T>
void Stack<T>::push(T val)
{
	mStack.push_back(val);
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
		return T();

	T val = mStack.back(); // get the last element 
	mStack.pop_back(); // pop the last element
	return val; // return the last
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return mStack.empty();
}

template <typename T>
std::string Stack<T>::toString() const
{
	std::stringstream ss;

	ss << "[";


	if (!isEmpty())
	{
		ss << mStack[0];
	}

	for (size_t i = 1; i < mStack.size(); ++i)
	{
		ss << ", " << mStack[i];
	}

	ss << "]";

	return ss.str();
}


// At the end of the cpp create explicit instantiations -- then indicate which ones you offer by placing in the public header as typedef
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
}
