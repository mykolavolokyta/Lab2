#include <iostream>
#include "Directory.h"

int main(int argc, char** argv)
{
    if (argc != 2) return 1;
    Directory dir(argv[1]);
    std::vector<std::string> files = dir.read();
    for (const auto& file : files) {
        std::cout << file << '\n';
    }
    return 0;
}

