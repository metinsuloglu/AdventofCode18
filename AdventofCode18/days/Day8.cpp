//
//  Advent of Code 2018
//  Day 8: Memory Maneuver
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day8.h"

int Day8::calculateSum(const std::vector<int>& numbers, int& index, int& part) {
    if(index >= numbers.size()) return 0;
    
    const int nChild = numbers[index], nMetadata = numbers[++index];
    std::vector<int> childrenSum;
    int sum = 0;
    
    for(int i = 0; i < nChild; i++)
        childrenSum.push_back(calculateSum(numbers, ++index, part));
    
    if(part == 1) sum = std::accumulate(childrenSum.begin(), childrenSum.end(), 0);
    if(nChild == 0 || part == 1) {
        for(int j = 0; j < nMetadata; j++)
            sum += numbers[++index];
    } else {
        for(int j = 0; j < nMetadata; j++) {
            int metadata = numbers[++index];
            if(metadata > nChild) continue;
            sum += childrenSum[metadata - 1];
        }
    }
    
    return sum;
}

void Day8::run(int part) {
    std::ifstream file("inputs/day8.txt");
    std::vector<int> numbers;
    int n;
    
    while(file >> n) numbers.push_back(n);
    
    int startIndex = 0;
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        std::cout << "Answer: " << calculateSum(numbers, startIndex, part) << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::cout << "Answer: " << calculateSum(numbers, startIndex, part) << std::endl;
    }
}

