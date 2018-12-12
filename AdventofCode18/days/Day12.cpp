//
//  Advent of Code 2018
//  Day 12: Subterranean Sustainability
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day12.h"

char Day12::toPlantChar(bool b) {
    if(b == true) return '#';
    else return '.';
}

std::string Day12::getRegion(std::unordered_map<int, bool>& plants, const int index) {
    std::string region = "";
    for(int i = -2; i <= 2; i++) region += toPlantChar(plants[index + i]);
    
    return region;
}

void Day12::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day12.txt");
    std::unordered_map<int, bool> plants;
    std::unordered_map<std::string, bool> rules;
    std::string initialState = "#.#####.#.#.####.####.#.#...#.......##..##.#.#.#.###..#.....#.####..#.#######.#....####.#....##....#";
    
    for(int i = 0; i < initialState.length(); i++)
        plants[i] = (initialState[i] == '#');
    
    std::string condition;
    char newState;
    for(std::string line: lines) {
        condition = line.substr(0, 5);
        newState = line[line.length() - 1];
        rules[condition] = (newState == '#');
    }
    
    std::unordered_map<int, bool> newPlants;
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        int sum = 0;
        for(int i = 0; i < 20; i++) {
            int minIndex = INT_MAX, maxIndex = INT_MIN;
            for(auto& [n, b]: plants) {
                if(b) {
                    minIndex = std::min(minIndex, n);
                    maxIndex = std::max(maxIndex, n);
                }
            }
            
            newPlants.clear();
            for(int j = minIndex - 2; j <= maxIndex + 2; j++) {
                std::string region = getRegion(plants, j);
                newPlants[j] = rules[region];
            }
            
            plants = newPlants;
        }
        
        for(auto& [n, b]: plants) if(b) sum += n;
        
        std::cout << "Answer: " << sum << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        long sum = 0;
        // long prevSum = 0;
        for(int i = 0; i < 101; i++) {
            int minIndex = INT_MAX, maxIndex = INT_MIN;
            for(auto& [n, b]: plants) {
                if(b) {
                    minIndex = std::min(minIndex, n);
                    maxIndex = std::max(maxIndex, n);
                }
            }
            
            newPlants.clear();
            for(int j = minIndex - 2; j <= maxIndex + 2; j++) {
                std::string region = getRegion(plants, j);
                newPlants[j] = rules[region];
            }
            
            plants = newPlants;
            
            /* After 100 iterations, the sum difference is always 57 */
            /*sum = 0;
            for(auto& [n, b]: plants) if(b) sum += n;
            std::cout << "Iteration " << i << " sum is " << sum << ", difference from previous: " << sum - prevSum << std::endl;
            prevSum = sum;*/
        }
        
        for(auto& [n, b]: plants) if(b) sum += n;
        
        std::cout << "Answer: " << sum + (50000000000 - 101) * 57 << std::endl;
        
        
    }
    
}

