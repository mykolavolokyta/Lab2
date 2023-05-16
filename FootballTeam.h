#pragma once
#include <string>
class FootballTeam {
private:
	std::string m_matches;
	std::string m_name;
	int m_score;
public:
	FootballTeam(std::string);
	void count_score();
	std::string get_name() const;
	int get_score() const;
};