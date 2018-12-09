//
//  Advent of Code 2018
//  Day 9: Marble Mania
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day9.h"

long Day9::maxGameScore(const int players, const int lastMarble) {
    std::list<long> marbles;
    
    std::vector<long> scores(players, 0);
    int currentPlayer = 0;
    long maxScore = INT_MIN;
    
    marbles.push_back(0);
    std::list<long>::iterator currentMarble = marbles.begin();
    
    for(int i = 1; i <= lastMarble; i++) {
        if(i % 23 == 0) {
            scores[currentPlayer] += i;
            for(int j = 0; j < 7; j++) {
                if(currentMarble == marbles.begin()) currentMarble = marbles.end();
                currentMarble--;
            }
            scores[currentPlayer] += *currentMarble;
            currentMarble = marbles.erase(currentMarble);
            if(currentMarble == marbles.end()) currentMarble = marbles.begin();
            
            if(scores[currentPlayer] > maxScore) maxScore = scores[currentPlayer];
        } else {
            for(int j = 0; j < 2; j++) {
                if(currentMarble == marbles.end()) currentMarble = marbles.begin();
                currentMarble++;
            }
            currentMarble = marbles.insert(currentMarble, i);
        }
        currentPlayer = (currentPlayer + 1) % players;
    }
    
    return maxScore;
}

void Day9::run(int part) {
    
    if(part == 1) {
        const int players = 455, lastMarble = 71223;
        
        std::cout << "~Part 1~" << std::endl;
        std::cout << "Answer: " << maxGameScore(players, lastMarble) << std::endl;
        
    } else {
        const int players = 455, lastMarble = 7122300;
        
        std::cout << "~Part 2~" << std::endl;
        std::cout << "Answer: " << maxGameScore(players, lastMarble) << std::endl;
    }
}

