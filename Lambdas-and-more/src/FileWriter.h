#pragma once
#include <mutex>
#include <string>


class FileWriter
{
public:
	explicit FileWriter(std::string fileName);
	~FileWriter();
	void writeToFile(const std::string& message);

private:
	std::string _fileName;
	std::mutex _mutex;
	int g_i = 0;
};
