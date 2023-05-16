#include "Reader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Reader::Reader(std::string filename): m_filename(filename){}

std::vector<std::string> Reader::read() const {
	std::ifstream in(m_filename);
	int number;
	in >> number;
	std::vector<std::string> rows;
	for (int i = 0; i < number + 1; i++) {
		std::string row;
		std::getline(in, row);
		if (i != 0) rows.push_back(row);
	}
	return rows;
}