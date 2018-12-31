//
//  Advent of Code 2018
//  Day 18: Settlers of The North Pole
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day18_h
#define Day18_h

#include "AoCDay.h"

class Day18 {
private:
    static int woodedCount, lumberyardCount;
public:
    static char newAcre(const std::vector<std::string>&, const int, const int);
    static void run(int);
};

#endif /* Day18_h */

