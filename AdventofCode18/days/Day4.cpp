//
//  Day4.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 04/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include "../headers/Day4.h"

struct DateTime {
    int year, month, day, hour, minute;
};

void Day4::run(int part) {
    std::vector<std::string> lines =  AoCDay::readFileLines("inputs/day4.txt");
    std::sort(lines.begin(), lines.end());
    
    DateTime time;
    std::string event;
    
    std::map<int, int> guardNapTotal; // Guard ID -> Total time slept
    std::map<int, std::map<int, int>> guardNapMins; // Guard ID -> Slept minutes -> Counts
    
    int currentGuard = -1, sleepMinute = -1, maxSleepID = -1; // Part 1
    int maxCount = INT_MIN, maxMinute = -1, maxMinuteID = -1; // Part 2
    
    for(std::string line: lines) {
        sscanf(line.c_str(), "[%d-%d-%d %d:%d]", &time.year, &time.month, &time.day, &time.hour, &time.minute);
        event = line.substr(line.find("]") + 2, line.size() - line.find("]") - 2);
        
        if(std::regex_match(event, std::regex("(Guard #\\d+ begins shift)"))) {
            currentGuard = stoi(event.substr(event.find("#") + 1, event.find("b") - event.find("#") - 2));
        } else if(event == "falls asleep") {
            sleepMinute = time.minute;
        } else if(event == "wakes up") {
            guardNapTotal[currentGuard] += time.minute - sleepMinute; // Add slept time to total sleep time
            if(guardNapTotal[currentGuard] > guardNapTotal[maxSleepID])
                maxSleepID = currentGuard; // Select guard which slept the most
            
            // Increase counts of minutes slept and select guard which has the largest count
            for(int i = time.minute - 1; i >= sleepMinute; i--) {
                if(++guardNapMins[currentGuard][i] > maxCount) {
                    maxMinuteID = currentGuard;
                    maxMinute = i;
                    maxCount = guardNapMins[currentGuard][i];
                }
            }
        }
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        int maxSleptMinCount = INT_MIN, maxSleptMin = 0;
        for(const auto& [minute, count]: guardNapMins[maxSleepID]) {
            if(count > maxSleptMinCount) { maxSleptMinCount = count; maxSleptMin = minute; }
        }
    
        std::cout << "Answer: " << maxSleepID * maxSleptMin << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::cout << "Answer: " << maxMinuteID * maxMinute << std::endl;
    }
}
