//
//  Day2.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 02/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include "../headers/Day2.h"

void Day2::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day2.txt");
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        std::map<char, int> counts;
        int twoCount = 0, threeCount = 0;
        bool twoFound, threeFound;
        
        for(std::string l: lines) {
            counts.clear();
            
            for(char c: l) counts[c]++;
            
            twoFound = false; threeFound = false;
            for(char c: l) {
                if(!twoFound && counts[c] == 2) { twoCount++; twoFound = true; }
                else if(!threeFound && counts[c] == 3) { threeCount++; threeFound = true; }
                
                if(twoFound && threeFound) break;
            }
        }
        std::cout << "Answer: " << twoCount * threeCount << std::endl;
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        int diff, diffPos;
        for(int i = 0; i < lines.size(); i++) {
            for(int j = i; j < lines.size(); j++) {
                diff = 0; diffPos = 0;
                for(int k = 0; k < lines[i].size(); k++) {
                    if(lines[i][k] != lines[j][k]) { diff++; diffPos = k; }
                    if (diff > 1) break;
                }
                if(diff == 1) {
                    std::cout << "Answer: " << lines[i].erase(diffPos, 1) << std::endl;
                    return;
                }
            }
        }
    }
}
