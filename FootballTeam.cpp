#include "FootballTeam.h"
#include <iostream>
#include <string>
#include "FootballMatch.h"

FootballTeam::FootballTeam(std::string name, std::vector<FootballMatch> matches): m_score(0), m_name(name), m_matches(matches) { }

std::string FootballTeam::get_name() const { return m_name; }
int FootballTeam::get_score() const { return m_score; }

void FootballTeam::count_score() {
    for (auto& match : m_matches) {
        m_score += match.get_points();
    }
}

bool FootballTeam::operator>(const FootballTeam& other) {
    return m_score > other.m_score;
}

FootballTeam::~FootballTeam() {}