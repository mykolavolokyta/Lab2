#include "FootballTeam.h"
#include <iostream>
#include <string>
#include "FootballMatch.h"

FootballTeam::FootballTeam(std::string row) {
    std::string::size_type pos = row.find(',');
    if (pos != std::string::npos)
    {
        m_name = row.substr(0, pos);
        m_matches = row.substr(pos + 1);
        m_score = 0;
    }
}

void FootballTeam::count_score() {
    std::string::size_type pos1 = 0, pos2 = 0;
    while ((pos2 = m_matches.find(',', pos2)) != std::string::npos) {
        FootballMatch match(m_matches.substr(pos1, pos2 - pos1));
        m_score += match.get_points();
        pos1 = pos2 + 1;
        ++pos2;
    }
    FootballMatch match(m_matches.substr(pos1));
    m_score += match.get_points();
}

std::string FootballTeam::get_name() const { return m_name; }
int FootballTeam::get_score() const { return m_score; }