#pragma once
#include <string>
#include <vector>
#include "FootballTeam.h"
#include "FootballMatch.h"

class Handler {
private:
	std::string m_row;
public:
	Handler(std::string);

	FootballTeam get_team() const;

	~Handler();
};

