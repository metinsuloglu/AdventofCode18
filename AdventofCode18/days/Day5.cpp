//
//  Day5.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 05/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include "../headers/Day5.h"

std::string react(std::string& polymer) {
    for(int i = 0; i < polymer.size() - 1; i++) {
        if((polymer[i+1] == polymer[i] + 32) || (polymer[i+1] == polymer[i] - 32)) {
            polymer.erase(i, 2);
            (i == 0) ? i = -1 : i -= 2;
        }
    }
    
    return polymer;
}

void Day5::run(int part) {
    std::string polymer = AoCDay::readFileAsString("inputs/day5.txt");
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        react(polymer);
        
        std::cout << "Answer: " << polymer.size() << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::string reset = polymer;
        int minLength = INT_MAX;
        for(int i = 'a'; i <= 'z'; i++) {
            polymer.erase(std::remove_if(polymer.begin(), polymer.end(),
                                         [i](char c){return c == i || c == i - 32;}), polymer.end());
            react(polymer);
            if(polymer.size() < minLength) { minLength = (int)polymer.size(); }
            polymer = reset;
        }
        
        std::cout << "Answer: " << minLength << std::endl;
        
    }
}
