#pragma once
#include <string>
#include <vector>
#include <filesystem>

class Directory {
private:
	std::string m_dirmame;
public:
	Directory(const char*);
	std::vector<std::string> read() const;
	~Directory();
};