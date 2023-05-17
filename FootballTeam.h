#pragma once
#include <string>
#include <vector>
#include "FootballMatch.h"

class FootballTeam {
private:
	std::string m_name;
	std::vector<FootballMatch> m_matches;
	int m_score;
public:
	FootballTeam(std::string, std::vector<FootballMatch>);
	
	std::string get_name() const;
	int get_score() const;

	void count_score();
	bool operator>(const FootballTeam&);

	~FootballTeam();
};