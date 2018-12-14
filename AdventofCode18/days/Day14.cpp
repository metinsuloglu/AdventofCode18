//
//  Advent of Code 2018
//  Day 14: Chocolate Charts
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day14.h"

void Day14::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day14.txt");
    std::vector<int> scoreboard {3, 7};
    int elves[2] = {0, 1};
    int nRecipes = 580741;
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        while(true) {
            int sum = scoreboard[elves[0]] + scoreboard[elves[1]];
            if(sum >= 10) { scoreboard.push_back(1); scoreboard.push_back(sum % 10); }
            else scoreboard.push_back(sum);
            
            if(scoreboard.size() == nRecipes + 10) break;
            elves[0] = (elves[0] + scoreboard[elves[0]] + 1) % scoreboard.size();
            elves[1] = (elves[1] + scoreboard[elves[1]] + 1) % scoreboard.size();
        }
        
        std::cout << "Answer: ";
        for(int i = nRecipes; i < scoreboard.size(); i++)
            std::cout << scoreboard[i];
        std::cout << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::string match = std::to_string(nRecipes);
        std::string toMatch = "37";
        
        while(true) {
            std::string sum = std::to_string(scoreboard[elves[0]] + scoreboard[elves[1]]);
            for(char d: sum) {
                scoreboard.push_back(d - '0');
                if(toMatch.length() < match.length()) toMatch += d;
                else toMatch = (toMatch + d).substr(1, toMatch.length());
                
                if(scoreboard.size() < match.length()) continue;
                
                if(toMatch == match) {
                    std::cout << "Answer: " << scoreboard.size() - match.length() << std::endl;
                    return;
                }
            }
            
            elves[0] = (elves[0] + scoreboard[elves[0]] + 1) % scoreboard.size();
            elves[1] = (elves[1] + scoreboard[elves[1]] + 1) % scoreboard.size();
            
        }
    }
    
}

