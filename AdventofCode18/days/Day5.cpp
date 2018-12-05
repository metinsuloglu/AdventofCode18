//
//  Advent of Code 2018
//  Day 5: Alchemical Reduction
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day5.h"

int react(std::string& polymer) {
    std::stack<char> s;
    for(char c: polymer) {
        if(s.empty()) s.push(c);
        else if(s.top() == c - 32 || s.top() == c + 32) s.pop();
        else s.push(c);
    }
    
    return (int)s.size();
}

void Day5::run(int part) {
    std::string polymer = AoCDay::readFileAsString("inputs/day5.txt");
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        std::cout << "Answer: " << react(polymer) << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::string reset = polymer;
        int minLength = INT_MAX;
        for(int i = 'a'; i <= 'z'; i++) {
            polymer.erase(std::remove_if(polymer.begin(), polymer.end(),
                                         [i](char c){return c == i || c == i - 32;}), polymer.end());
            minLength = std::min(react(polymer), minLength);
            polymer = reset;
        }
        
        std::cout << "Answer: " << minLength << std::endl;
        
    }
}
