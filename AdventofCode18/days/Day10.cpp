//
//  Advent of Code 2018
//  Day 10: The Stars Align
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day10.h"

void printSky(std::vector<std::valarray<int>> points) {
    
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    for(const auto& p: points) {
        minX = std::min(p[0], minX);
        minY = std::min(p[1], minY);
        maxX = std::max(p[0], maxX);
        maxY = std::max(p[1], maxY);
    }
    
    int r = maxX - minX + 1, c = maxY - minY + 1;
    char sky[r][c];
    
    // std::cout << r << "x" << c << std::endl; // Size of bounding box
    
    for(int j = 0; j < c; j++)
        for(int i = 0; i < r; i++)
            sky[i][j] = '.';
    
    for(const std::valarray<int>& p: points)
        sky[p[0] - minX][p[1] - minY] = '#';
    
    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++)
            std::cout << sky[i][j];
        std::cout << std::endl;
    }
}


void Day10::run(int iterLow, int iterHi) {
    
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day10.txt");
    
    std::vector<std::valarray<int>> points;
    std::vector<std::valarray<int>> velocities;
    
    int x, y, dx, dy;
    for(std::string line: lines) {
        sscanf(line.c_str(), "position=<%d, %d> velocity=<%d, %d>", &x, &y, &dx, &dy);
        points.push_back({x, y});
        velocities.push_back({dx, dy});
    }
    
    std::cout << "~Parts 1 and 2~" << std::endl;
    
    int iter = 0;
    while(++iter) {
        for(int i = 0; i < points.size(); i++)
            points[i] += velocities[i];
        
        if(iter >= iterLow) {
            std::cout << "\nIteration " << iter << ":" << std::endl;
            printSky(points);
            if(iter == iterHi) break;
        }
    }
    
    std::cout << std::endl;
    
}

