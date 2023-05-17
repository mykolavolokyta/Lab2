#include "FootballMatch.h"
#include <sstream>
#include <iostream>

FootballMatch::FootballMatch(std::string match): m_match(match){}

int FootballMatch::get_points() const {
	int a, b;
	char delim;
	std::stringstream ss(m_match);
	if (ss >> a >> delim >> b);
	if (!ss || delim != ':' || ss.rdbuf()->in_avail() != 0) {
		throw std::exception(("[ERROR] Cannot get result of match: " + m_match).c_str());
	}
	if (a > b) return 3;
	if (a == b) return 1;
	return 0;
}

FootballMatch::~FootballMatch() {}