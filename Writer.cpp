#include "Writer.h"
#include <fstream>
#include <exception>

Writer::Writer(std::string filename) : m_filename(filename) {
	std::ofstream out(m_filename);
	if (!out) {
		throw std::exception(("[ERROR] Cannot create a file with name \"" + m_filename + "\".").c_str());
	}
	out.close();
}

void Writer::write(std::vector<FootballTeam> teams) {
	std::ofstream out(m_filename);
	for (auto& team : teams) {
		out << team.get_name() << ',' << team.get_score() << '\n';
	}
}

Writer::~Writer() {}