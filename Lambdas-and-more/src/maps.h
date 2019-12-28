#pragma once

#include <map>
#include <string>
#include <iostream>
#include <unordered_map>

inline void testOrderedMap()
{
	std::map<std::string, int> wordCountMap;
	wordCountMap.insert(std::make_pair("Hello", 2));
	wordCountMap.insert(std::make_pair("Duhhh", 3));
	wordCountMap.insert(std::make_pair("Aaaa", 8));
	wordCountMap.insert(std::make_pair("Abbb", 9));
	wordCountMap.insert(std::make_pair("Aabb", 10));

	auto it = wordCountMap.begin();


	for (std::pair<std::string, int> pair : wordCountMap)
	{
		std::cout << pair.first << " appears " << pair.second << " times." << std::endl;
	}
	std::cout << std::endl;
}

inline void testUnorderedMap()
{
	std::unordered_map<std::string, int> wordCountMap;
	wordCountMap.insert(std::make_pair("Hello", 2));
	wordCountMap.insert(std::make_pair("Duhhh", 3));
	wordCountMap.insert(std::make_pair("Aaaa", 8));
	wordCountMap.insert(std::make_pair("Abbb", 9));
	wordCountMap.insert(std::make_pair("Aabb", 10));

	for (std::pair<std::string, int> pair : wordCountMap)
	{
		std::cout << pair.first << " appears " << pair.second << " times." << std::endl;
	}
	std::cout << std::endl;
}
