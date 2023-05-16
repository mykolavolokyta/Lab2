#include <iostream>
#include "Directory.h"
#include "functions.h"
#include "DirectoryNotFoundException.h"

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
                std::cout << file << '\n';
            }
        }
    }
    catch (DirectoryNotFoundException& exception)
    {
        std::cout << exception.what();
    }
    return 0;
}
