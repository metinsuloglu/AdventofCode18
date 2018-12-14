//
//  Advent of Code 2018
//  Day 3: No Matter How You Slice It
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day3_h
#define Day3_h

#include "AoCDay.h"

struct Rect {
    int ID;
    int x, y;
    int w, h;
    
    Rect(std::string&, std::string&, std::string&);
};

class Day3 {
public:
    static void run(int);
};

#endif /* Day3_h */
