#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "Directory.h"
#include "functions.h"
#include "DirectoryNotFoundException.h"
#include "Reader.h"

int main(int argc, char** argv)
{
    if (argc != 2)  {
        std::cout << "[ERROR] Incorrect input. Usage: Lab2.exe path/to/dir";
        return 1;
    }
    try {
        Directory dir(argv[1]);
        std::vector<std::string> files = dir.read();
        for (const auto& file : files) {
            if (csv::is_csv(file)) {
                Reader reader(file);
                auto rows = reader.read();
                for (auto row : rows) {
                    std::cout << row << '\n';
                }
            }
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
