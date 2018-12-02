//
//  Day1.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 01/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include "AoCDay.h"

class Day1 {
public:
    static void run(int part) {
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
};
