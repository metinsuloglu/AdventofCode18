//
//  Advent of Code 2018
//  Day 6: Chronal Coordinates
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day6.h"

int Day6::manhattanDistanceBetween(const Point& p1, const Point& p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

std::vector<Point> Day6::getClosestCoords(const std::vector<Point>& coords, const Point& p) {
    int minDist = INT_MAX, dist;
    std::vector<Point> closest;
    for(Point coord: coords) {
        dist = manhattanDistanceBetween(coord, p);
        if(dist == minDist) closest.push_back(coord);
        else if(dist < minDist) {
            minDist = dist;
            closest.clear();
            closest.push_back(coord);
        }
    }
    return closest;
}

int Day6::sumToAllCoords(const std::vector<Point>& coords, const Point& p) {
    int sum = 0;
    for(Point coord: coords)
        sum += manhattanDistanceBetween(coord, p);
    return sum;
}

void Day6::run(int part) {
    std::vector<std::string> lines = AoCDay::readFileLines("inputs/day6.txt");
    
    std::vector<Point> coords;
    std::set<Point> infCoords;
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    
    int x, y;
    for(std::string line: lines) {
        sscanf(line.c_str(), "%d, %d", &x, &y);
        coords.push_back(Point(x, y));
        if (x < minX) minX = x;
        if (y < minY) minY = y;
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }
    
    /* Exclude infinite coordinates */
    std::vector<Point> closestPoints;
    for(int i = minX; i <= maxX; i++) {
        closestPoints = getClosestCoords(coords, Point(i, minY));
        if(closestPoints.size() > 1) continue;
        infCoords.insert(closestPoints[0]);
        closestPoints = getClosestCoords(coords, Point(i, maxY));
        if(closestPoints.size() > 1) continue;
        infCoords.insert(closestPoints[0]);
    }
    for(int i = minY + 1; i < maxY; i++) {
        closestPoints = getClosestCoords(coords, Point(minX, i));
        if(closestPoints.size() > 1) continue;
        infCoords.insert(closestPoints[0]);
        closestPoints = getClosestCoords(coords, Point(maxX, i));
        if(closestPoints.size() > 1) continue;
        infCoords.insert(closestPoints[0]);
    }
    /**/
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        std::map<Point, int> areas;
        
        int maxArea = INT_MIN;
        for(int j = minY; j <= maxY; j++) {
            for(int i = minX; i <= maxX; i++) {
                Point minPoint;
                int minDist = INT_MAX;
                bool equalDist = false;
                for(const Point& coord: coords) {
                    int dist = manhattanDistanceBetween(coord, Point(i, j));
                    if(dist == minDist) equalDist = true;
                    if(dist < minDist) {
                        equalDist = false;
                        minDist = dist;
                        minPoint = coord;
                    }
                }
                if(!equalDist) {
                    areas[minPoint]++;
                    if(areas[minPoint] > maxArea && !infCoords.count(minPoint)) maxArea = areas[minPoint];
                }
            }
        }
        
        if(maxArea == INT_MIN) std::cout << "Answer: All coordinates have infinite area." << std::endl;
        else std::cout << "Answer: " << maxArea << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        const int regionDist = 10000;
        int totalArea = 0;
        
        minX -= int(regionDist / coords.size());
        minY -= int(regionDist / coords.size());
        maxX += int(regionDist / coords.size());
        maxY += int(regionDist / coords.size());
        for(int j = minY; j <= maxY; j++)
            for(int i = minX; i <= maxX; i++)
                if(sumToAllCoords(coords, Point(i, j)) < regionDist) totalArea++;
        
        std::cout << "Answer: " << totalArea << std::endl;
    }
}

