#pragma once
#include <iostream>

inline void testConstPointers()
{
	int a = 12;
	// const pointer -- cannot modify the value that it points to
	const int* b = &a;

	// non const pointer -- you can modify the value that it points to. 
	int* c = &a;

	std::cout << "Here is the const pointer: " << *b << std::endl;
	// Attempt to manipulate the object that the pointer is pointing to
	// int newVal = ++(*b); //--> this does not work

	// This does work
	int newVal = ++(*c);
	std::cout << "Here is the new value : " << newVal << std::endl;
	std::cout << "Here is the const pointer after modification: " << *b << std::endl;

}
