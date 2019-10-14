#pragma once
#include <iostream>

/**
 *	**PARAMETER PACKS**
 * These are called variadic packs
 * You can use them by getting the first arg then use recursion to get the rest
 * this is shown below!!!
 * YOU CANNOT ITERATE OVER THEM SO YOU USE RECURSION
 * const reference should be fine
 * NOTE ==> VERY IMPORTANT: you HAVE to provide a base case for the recursion (empty arg)
 */


//base case zero arguments 
void printArgs();
template <typename Arg, typename ...Args>
void printArgs(const Arg& first, const Args&... rest)
{
	std::cout << first << std::endl;
	printArgs(rest...); //recurse the rest until you hit zero arg base case
}

int runParameterPackExample();