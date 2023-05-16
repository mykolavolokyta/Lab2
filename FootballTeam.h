#pragma once
#include <string>
class FootballTeam {
private:
	std::string m_matches;
	std::string m_name;
	int m_score;
public:
	FootballTeam(std::string);
	
	std::string get_name() const;
	int get_score() const;

	void count_score();
	bool operator>(const FootballTeam&);

	~FootballTeam();
};