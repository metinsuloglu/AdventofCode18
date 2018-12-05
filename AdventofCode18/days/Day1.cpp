//
//  Advent of Code 2018
//  Day 1: Chronal Calibration
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day1.h"

void Day1::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day1.txt");
    
    int freq = 0;
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        for (std::string n: lines)
            freq += stoi(n);
        std::cout << "Answer: " << freq << std::endl;
    } else {
        std::cout << "~Part 2~" << std::endl;
        std::unordered_set<int> seen;
        while(true) {
            for (std::string n: lines) {
                freq += stoi(n);
                if(seen.find(freq) != seen.end()) {
                    std::cout << "Answer: " << freq << std::endl;
                    return;
                }
                seen.insert(freq);
            }
        }
    }
}
