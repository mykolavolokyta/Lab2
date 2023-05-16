#include "functions.h"

bool csv::is_csv(std::string filename) {
	return filename.substr(filename.find_last_of(".") + 1) == "csv";
}
