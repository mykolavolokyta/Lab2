#pragma once
#include <string>

class FootballMatch {
private:
	std::string m_match;
public:
	FootballMatch(std::string);

	int get_points() const;

	~FootballMatch();
};