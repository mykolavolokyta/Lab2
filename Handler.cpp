#include "Handler.h"
#include "FootballTeam.h"
#include <exception>

Handler::Handler(std::string row): m_row(row) {}

FootballTeam Handler::get_team() const {
    std::string team_name, team_matches;
    
    std::string::size_type pos = m_row.find(',');
    if (pos != std::string::npos)
    {
        team_name = m_row.substr(0, pos);
        if (team_name.find_first_not_of(' ') == std::string::npos) {
            throw std::exception("[ERROR] Cannot find team name.");
        }
        team_matches = m_row.substr(pos + 1);
    }

    std::vector<FootballMatch> matches;
    std::string::size_type pos1 = 0, pos2 = 0;
    while ((pos2 = team_matches.find(',', pos2)) != std::string::npos) {
        FootballMatch match(team_matches.substr(pos1, pos2 - pos1));
        matches.push_back(match);
        pos1 = pos2 + 1;
        ++pos2;
    }
    FootballMatch match(team_matches.substr(pos1));
    matches.push_back(match);
    return FootballTeam(team_name, matches);
}

Handler::~Handler() {}