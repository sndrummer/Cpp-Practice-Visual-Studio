#pragma once
#include <list>
#include <iostream>

// std::find is very useful -- parameters are first, last, value to compare the elements to
/*
 * This function gets the occurrences of a value in a list using std::find
 * go to the next value in the list after finding it 
 */
inline int getOccurrences(std::list<int>& list, const int value)
{
	auto occurrences = 0;

	auto result = std::find(std::begin(list), std::end(list), value);
	while (result != list.end())
	{
		// find another match if there is one
		result = std::find(++result, std::end(list), value);
		occurrences++;
	}

	return occurrences;
}

// Static function outside of a class -- means internal linkage -- this means that each file gets their own version of the function 
static void cantCallMe()
{
	std::cout << "static function called -- this file now has its OWN VERSION OF THIS FUNCTION!!!! " << std::endl;
}

inline void practiceLists()
{
	std::list<int> numberList;

	numberList.push_back(12);
	numberList.push_back(12);
	numberList.push_front(14);
	numberList.push_front(111);
	numberList.push_front(111);
	numberList.push_front(111);
	numberList.push_front(111);
	

	for (auto number : numberList)
	{
		std::cout << "The number " << number << " is in the list " << getOccurrences(numberList, number)  << " times"<< std::endl;
	}

	std::cout << "The number " << 0 << " is in the list " << getOccurrences(numberList, 0) << " times" << std::endl;
	cantCallMe();
}

