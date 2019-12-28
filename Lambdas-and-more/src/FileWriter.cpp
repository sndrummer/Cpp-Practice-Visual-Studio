#include "FileWriter.h"
#include <iostream>
#include <thread>
#include <fstream>
#include <stdexcept>

FileWriter::FileWriter(std::string fileName)
	: _fileName(std::move(fileName))
{
}

FileWriter::~FileWriter() = default;

void FileWriter::writeToFile(const std::string& message)
{
	//protect access to a file by using a _mutex
	//lock the _mutex before accessing the file 
	std::lock_guard<std::mutex> lock(_mutex);
	// lock_guard makes it so mutex is automatically released when lock
	// goes out of scope

	++g_i;
	
	//try to open the file
	std::ofstream file;
	file.open(_fileName, std::ios_base::app);
	if (!file.is_open())
	{
		throw std::runtime_error("Unable to open file");
	}

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	//write the message to the file
	file << message << std::endl;
}
