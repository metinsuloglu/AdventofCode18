//
//  Advent of Code 2018
//  Day 13: Mine Cart Madness
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day13_h
#define Day13_h

#include "AoCDay.h"

enum Direction { UP, RIGHT, DOWN, LEFT };
enum TurnDirection { TURNLEFT, GOSTRAIGHT, TURNRIGHT };

struct Cart {
    int x, y;
    
    Direction direc;
    TurnDirection currTurn;
    bool crashed;
    
    Cart(int, int, char);
    void turn();
    void turnLeft();
    void turnRight();
    void turnCorner(const char&);
    void advance();
    bool isCrashed() const;
    bool isCrashedWith(const Cart&) const;
};

class Day13 {
public:
    static void run(int);
};

#endif /* Day13_h */

