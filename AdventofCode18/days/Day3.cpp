//
//  Advent of Code 2018
//  Day 3: No Matter How You Slice It
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day3.h"

struct Rect {
    int id;
    int x, y;
    int w, h;
    
    Rect(std::string& id, std::string& loc, std::string& size) {
        this->id = std::stoi(id);
        this->x = std::stoi(loc.substr(0, loc.find(",")));
        this->y = std::stoi(loc.substr(loc.find(",") + 1, loc.size()));
        this->w = std::stoi(size.substr(0, size.find("x")));
        this->h = std::stoi(size.substr(size.find("x") + 1, size.size()));
    }
};

void Day3::run(int part) {
    std::ifstream file("inputs/day3.txt", std::ios::in);
    std::string claim;
    std::map<std::tuple<int, int>, int> locCounts;
    std::vector<Rect> rects;
    
    while(getline(file, claim)) {
        std::string id = claim.substr(1, claim.find("@") - 2);
        std::string loc = claim.substr(claim.find("@") + 2, claim.find(":") - claim.find("@") - 2);
        std::string size = claim.substr(claim.find(":") + 2, claim.size() - claim.find(":") - 2);
        
        Rect rect = Rect(id, loc, size);
        for(int i = rect.x; i < rect.x + rect.w; i++)
            for(int j = rect.y; j < rect.y + rect.h; j++)
                locCounts[std::make_tuple(i, j)]++;
        
        rects.push_back(rect);
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        int area = 0;
        
        for(const auto& [loc, count]: locCounts) if(count > 1) area++;
        
        std::cout << "Answer: " << area << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        bool overlaps;
        
        for(Rect rect: rects) {
            overlaps = false;
            
            for(int i = rect.x; i < rect.x + rect.w; i++) {
                for(int j = rect.y; j < rect.y + rect.h; j++)
                    if(locCounts[std::make_tuple(i, j)] > 1) { overlaps = true; break; }
                if(overlaps) break;
            }
            
            if(!overlaps) { std::cout << "Answer: " << rect.id << std::endl; return; }
        }
    }
}
