#include "FootballMatch.h"
#include <sstream>
#include <iostream>

FootballMatch::FootballMatch(std::string match): m_match(match){}

int FootballMatch::get_points() const {
	int a, b;
	char delim;
	std::stringstream ss(m_match);
	ss >> a >> delim >> b;
	if (a > b) return 3;
	if (a == b) return 1;
	return 0;
}