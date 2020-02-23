#pragma once
#include <vector>
#include <iostream>

inline void vectorPractice()
{
	std::vector<size_t> a;

	a.push_back(12);
	a.push_back(13);
	a.push_back(14);

	std::cout << "Here is the first element " << a[0] << std::endl;

	// use the for each style because the other way is outdated
	// Remember that you can pass by reference to CHANGE the values
	// use a reference if you want to change 
	for (auto& num : a)
	{
		std::cout << num << std::endl;
		num++; // (you are incrementing the entire thing )
	}

	std::cout << "------------------" << std::endl;

	for (auto num : a)
	{
		std::cout << num << std::endl;
	}

	
}
