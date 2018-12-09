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
    int id;
    int x, y;
    int w, h;
    
    Rect(std::string& id, std::string& loc, std::string& size) {
        this->id = std::stoi(id);
        this->x = std::stoi(loc.substr(0, loc.find(",")));
        this->y = std::stoi(loc.substr(loc.find(",") + 1, loc.size()));
        this->w = std::stoi(size.substr(0, size.find("x")));
        this->h = std::stoi(size.substr(size.find("x") + 1, size.size()));
    }
};

class Day3 {
public:
    static void run(int);
};

#endif /* Day3_h */
