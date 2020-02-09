#pragma once

class Test
{
public:
	Test() = default;
	virtual ~Test() = default;

	Test(const Test& other) = delete;
	Test(Test&& other) noexcept = delete;
	Test& operator=(const Test& other) = delete;
	Test& operator=(Test&& other) noexcept = delete;
	
};

