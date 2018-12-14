//
//  Advent of Code 2018
//  Day 6: Chronal Coordinates
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day6_h
#define Day6_h

#include "AoCDay.h"

struct Point {
    int x, y;
    
    Point();
    Point(int, int);
    bool operator<(const Point&) const;
};

class Day6 {
public:
    static void run(int);
    static int manhattanDistanceBetween(const Point&, const Point&);
    static std::vector<Point> getClosestCoords(const std::vector<Point>&, const Point&);
    static int sumToAllCoords(const std::vector<Point>&, const Point&);
};

#endif /* Day6_h */

