#pragma once
#include <exception>
#include <string>

class FileCannotBeCreatedException : public std::exception {
private:
	std::string m_error;
public:
	FileCannotBeCreatedException(std::string error) : m_error(error) {}
	const char* what() const noexcept { return m_error.c_str(); }
};