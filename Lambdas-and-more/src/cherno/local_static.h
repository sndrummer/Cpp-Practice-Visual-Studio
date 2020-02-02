#pragma once
#include <iostream>

namespace Cherno
{
	inline void Function()
	{
		static int i = 0;
		i++;
		std::cout << i << std::endl;
	}
}
