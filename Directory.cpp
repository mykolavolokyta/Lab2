#include "Directory.h"
#include "DirectoryNotFoundException.h"

Directory::Directory(const char* dirname): m_dirmame(dirname){}

std::vector<std::string> Directory::read() const {
	std::filesystem::path path(m_dirmame);
	
	if (!std::filesystem::is_directory(path)) {
		throw DirectoryNotFoundException("[ERROR] Directory with name \"" + m_dirmame + "\" not found.");
	}
	
	std::vector<std::string> files;
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		files.push_back(entry.path().u8string());
	}

	return files;
}


Directory::~Directory(){}