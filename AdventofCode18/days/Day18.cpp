//
//  Advent of Code 2018
//  Day 18: Settlers of The North Pole
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day18.h"

int Day18::woodedCount = 0;
int Day18::lumberyardCount = 0;

char Day18::newAcre(const std::vector<std::string>& lca, const int x, const int y) {
    int neighbourCounts[3] = {0}; // open, wooded, lumberyard
    for(int yy = std::max(y - 1, 0); yy <= std::min(y + 1, (int)lca.size() - 1); yy++) {
        for(int xx = std::max(x - 1, 0); xx <= std::min(x + 1, (int)lca[yy].size() - 1); xx++) {
            if(yy == y && xx == x) continue;
            else if(lca[yy][xx] == '.') neighbourCounts[0]++;
            else if(lca[yy][xx] == '|') neighbourCounts[1]++;
            else if(lca[yy][xx] == '#') neighbourCounts[2]++;
        }
    }
    
    switch(lca[y][x]) {
        case '.':
            if(neighbourCounts[1] >= 3) {
                woodedCount++;
                return '|';
            }
            else return '.';
        case '|':
            if(neighbourCounts[2] >= 3) {
                woodedCount--;
                lumberyardCount++;
                return '#';
            }
            else return '|';
        case '#':
            if(neighbourCounts[2] >= 1 && neighbourCounts[1] >= 1) return '#';
            else {
                lumberyardCount--;
                return '.';
            }
        default:
            return lca[y][x];
    }
}

void Day18::run(int part) {
    std::vector<std::string> lumberCollectionArea = AoCDay::readFileLines("inputs/day18.txt");
    std::vector<std::string> updatedArea(lumberCollectionArea);

    woodedCount = 0;
    lumberyardCount = 0;
    for(int j = 0; j < lumberCollectionArea.size(); j++) {
        for(int i = 0; i < lumberCollectionArea[j].size(); i++) {
            if(lumberCollectionArea[j][i] == '|') woodedCount++;
            else if(lumberCollectionArea[j][i] == '#') lumberyardCount++;
        }
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        for(int min = 0; min < 10; min++) {
            for(int j = 0; j < lumberCollectionArea.size(); j++) {
                for(int i = 0; i < lumberCollectionArea[j].length(); i++)
                    updatedArea[j][i] = newAcre(lumberCollectionArea, i, j);
            }
            lumberCollectionArea = updatedArea;
        }
        
        std::cout << "Answer: " << woodedCount * lumberyardCount << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::map<std::vector<std::string>, int> seen;
        bool repeated = false;
        
        for(int min = 0; min < 1e9; min++) {
            for(int j = 0; j < lumberCollectionArea.size(); j++) {
                for(int i = 0; i < lumberCollectionArea[j].length(); i++)
                    updatedArea[j][i] = newAcre(lumberCollectionArea, i, j);
            }
            if(!repeated) {
                if(seen.find(updatedArea) != seen.end()) {
                    repeated = true;
                    min = 1e9 - ((int)(1e9 - min) % (min - seen[updatedArea]));
                } else seen[updatedArea] = min;
            }
            lumberCollectionArea = updatedArea;
        }
        
        std::cout << "Answer: " << woodedCount * lumberyardCount << std::endl;
        
    }
}

