//
//  Advent of Code 2018
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef AoCDay_h
#define AoCDay_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <regex>

class AoCDay {
public:
    static std::vector<std::string> readFileLines(const std::string& fileName);
    static std::string readFileAsString(const std::string& fileName);
};

#endif /* AoCDay_h */
