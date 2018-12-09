//
//  Advent of Code 2018
//  Day 7: The Sum of Its Parts
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day7.h"

void Day7::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day7.txt");
    
    std::unordered_map<char, std::vector<char>> requirements;
    std::unordered_map<char, bool> done;
    
    char first, then;
    std::unordered_set<char> nodes;
    for(std::string line: lines) {
        first = line[5];
        then = line[36];
        
        requirements[then].push_back(first);
        nodes.insert(first);
        nodes.insert(then);
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        std::cout << "Answer: ";
        while(nodes.size() != 0) {
            std::vector<char> next;
            bool allCompleted;
            for(char node: nodes) {
                allCompleted = true;
                for(char r: requirements[node]) {
                    if(!done[r]) { allCompleted = false; break; }
                }
                if(allCompleted) next.push_back(node);
            }
            
            std::sort(next.begin(), next.end());
            
            done[next[0]] = true;
            std::cout << next[0];
            
            nodes.erase(next[0]);
        }
        std::cout << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::unordered_set<char> currJobs; // Jobs currently being performed
        int time = 0;
        
        const int numWorkers = 5;
        const int stepTime = 60;
        
        std::vector<char> workers(numWorkers);
        std::vector<int> counters(numWorkers);
        
        for(int i = 0; i < numWorkers; i++) counters[i] = -1; // Initialize counters
        
        while(true) {
            std::vector<char> next;
            bool allCompleted;
            for(char node: nodes) {
                allCompleted = true;
                for(char r: requirements[node]) {
                    if(!done[r]) { allCompleted = false; break; }
                }
                if(allCompleted && !currJobs.count(node)) next.push_back(node);
            }
            
            std::sort(next.begin(), next.end());
            
            // Assign workers jobs
            for(char n: next) {
                for(int i = 0; i < numWorkers; i++) {
                    if(counters[i] == -1) {
                        workers[i] = n;
                        counters[i] = n - 'A' + stepTime + 1;
                        currJobs.insert(n);
                        break;
                    }
                }
            }
            
            if(currJobs.empty()) break; // No worker is working on anything exit loop
            
            // Decrease counters
            int minTime = INT_MAX;
            for(int currTime: counters) if(currTime != -1 && currTime < minTime) minTime = currTime;
            for(int i = 0; i < numWorkers; i++) {
                if(counters[i] > -1) {
                    counters[i] -= minTime;
                    if(counters[i] == 0) { // Work finished
                        done[workers[i]] = true;
                        counters[i] = -1;
                        currJobs.erase(workers[i]);
                        nodes.erase(workers[i]);
                    }
                }
            }
            
            time += minTime;
        }
        
        std::cout << "Answer: " << time << std::endl;
        
    }
}

