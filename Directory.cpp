#include "Directory.h"

Directory::Directory(const char* dirname): m_dirmame(dirname){}

std::vector<std::string> Directory::read() const {
	std::filesystem::path path(m_dirmame);
	std::vector<std::string> files;
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		files.push_back(entry.path().u8string());
	}

	return files;
}


Directory::~Directory(){}