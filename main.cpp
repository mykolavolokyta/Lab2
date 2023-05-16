#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include "Directory.h"
#include "functions.h"
#include "DirectoryNotFoundException.h"
#include "Reader.h"
#include "FootballTeam.h"

int main(int argc, char** argv)
{
    if (argc != 2)  {
        std::cout << "[ERROR] Incorrect input. Usage: Lab2.exe path/to/dir";
        return 1;
    }
    try {
        Directory dir(argv[1]);
        std::vector<std::string> files = dir.read();
        std::vector<FootballTeam> teams;
        for (const auto& file : files) {
            if (csv::is_csv(file)) {
                Reader reader(file);
                auto rows = reader.read();
                for (const auto& row : rows) {
                    FootballTeam team(row);
                    team.count_score();
                    teams.push_back(team);
                }
            }
        }
        std::sort(teams.begin(), teams.end(), std::greater<>());
        for (auto& team : teams) {
            std::cout << team.get_name() << ": " << team.get_score() << '\n';
        }
    }
    catch (DirectoryNotFoundException& exception)
    {
        std::cout << exception.what();
    }
    catch (std::exception& exception)
    {
        std::cout << exception.what();
    }
    return 0;
}
