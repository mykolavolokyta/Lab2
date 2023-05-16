#pragma once
#include <string>
#include <vector>
class Reader {
private:
	std::string m_filename;
public:
	Reader(std::string);
	std::vector<std::string> read() const;
};