//
//  Advent of Code 2018
//  Day 11: Chronal Charge
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day11.h"

void Day11::run(int part) {
    
    const int gridSize = 300, gridSerialNumber = 3214;
    int sumGrid[gridSize + 1][gridSize + 1];
    
    int powerLevel, rackID;
    for(int j = 0; j < gridSize + 1; j++) {
        for(int i = 0; i < gridSize + 1; i++) {
            if(i == 0 || j == 0) { sumGrid[i][j] = 0; continue; }
            rackID = i + 10;
            powerLevel = rackID * (j) + gridSerialNumber;
            powerLevel *= rackID;
            powerLevel = ((powerLevel / 100) % 10) - 5;
            sumGrid[i][j] = powerLevel + sumGrid[i][j - 1] + sumGrid[i - 1][j] - sumGrid[i - 1][j - 1];
        }
    }
    
    int maxSum = INT_MIN, sum, maxX = 0, maxY = 0, maxSumSize = 0;
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        for(int j = 3; j < gridSize + 1; j++) {
            for(int i = 3; i < gridSize + 1; i++) {
                sum = sumGrid[i][j] - sumGrid[i - 3][j] - sumGrid[i][j - 3] + sumGrid[i - 3][j - 3];
                if(sum > maxSum) {
                    maxSum = sum;
                    maxX = i - 2; maxY = j - 2;
                }
            }
        }
        
        std::cout << "Answer: " << maxX << "," << maxY << std::endl;
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        for(int size = 1; size <= 300; size++) {
            for(int j = size; j < gridSize + 1; j++) {
                for(int i = size; i < gridSize + 1; i++) {
                    sum = sumGrid[i][j] - sumGrid[i - size][j] - sumGrid[i][j - size] + sumGrid[i - size][j - size];
                    if(sum > maxSum) {
                        maxSum = sum;
                        maxX = i - size + 1; maxY = j - size + 1;
                        maxSumSize = size;
                    }
                }
            }
        }
        
        std::cout << "Answer: " << maxX << "," << maxY << "," << maxSumSize << std::endl;
    }
    
}

