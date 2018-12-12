//
//  Advent of Code 2018
//  Day 12: Subterranean Sustainability
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day12_h
#define Day12_h

#include "AoCDay.h"

class Day12 {
public:
    static char toPlantChar(bool);
    static void run(int);
    static std::string getRegion(std::unordered_map<int, bool>&, const int);
};

#endif /* Day12_h */

