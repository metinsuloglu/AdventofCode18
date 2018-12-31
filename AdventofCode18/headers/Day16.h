//
//  Advent of Code 2018
//  Day 16: Chronal Classification
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#ifndef Day16_h
#define Day16_h

#include "AoCDay.h"

enum Opcode { na, addr, addi, mulr, muli, banr, bani, borr, bori, setr, seti, gtir, gtri, gtrr, eqir, eqri, eqrr };

struct Instruction {
    Opcode opcode;
    int A, B, C;
    
    std::vector<int> execute(std::vector<int>);
    void reset();
};

class Day16 {
public:
    static void run(int);
};

#endif /* Day16_h */

