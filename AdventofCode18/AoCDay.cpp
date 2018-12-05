//
//  Advent of Code 2018
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "AoCDay.h"

std::vector<std::string> AoCDay::readFileLines(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::in);
    std::string line;
    std::vector<std::string> lines;
    while(getline(file, line))
        lines.push_back(line);
    return lines;
}

std::string AoCDay::readFileAsString(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::in);
    std::string line;
    std::string readString = "";
    while(getline(file, line))
        readString.append(line);
    return readString;
}
