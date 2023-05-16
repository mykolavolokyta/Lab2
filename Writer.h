#pragma once
#include <string>
#include <vector>
#include "FootballTeam.h"

class Writer {
private:
	std::string m_filename;
public:
	Writer(std::string);

	void write(std::vector<FootballTeam>);

	~Writer();
};