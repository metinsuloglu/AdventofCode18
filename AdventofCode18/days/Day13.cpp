//
//  Advent of Code 2018
//  Day 13: Mine Cart Madness
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day13.h"

Cart::Cart(int x, int y, char c) {
    this->x = x; this->y = y;
    this->crashed = false;
    if(c == '^') this->direc = UP;
    else if(c == '>') this->direc = RIGHT;
    else if(c == 'v') this->direc = DOWN;
    else this->direc = LEFT;
    this->currTurn = TURNLEFT;
}
void Cart::turn() {
    if(currTurn == TURNLEFT) turnLeft();
    else if(currTurn == TURNRIGHT) turnRight();
    currTurn = TurnDirection((currTurn + 1) % 3);
}
void Cart::turnLeft() {
    direc = Direction((direc + 3) % 4);
}
void Cart::turnRight() {
    direc = Direction((direc + 1) % 4);
}
void Cart::turnCorner(const char& c) {
    if(c == '/') {
        if(direc == UP || direc == DOWN) turnRight();
        else if(direc == LEFT || direc == RIGHT) turnLeft();
    } else if(c == '\\') {
        if(direc == UP || direc == DOWN) turnLeft();
        else if(direc == LEFT || direc == RIGHT) turnRight();
    }
}
void Cart::advance() {
    if(direc == UP) y--;
    else if(direc == RIGHT) x++;
    else if(direc == DOWN) y++;
    else if(direc == LEFT) x--;
}
bool Cart::isCrashed() const {
    return crashed;
}
bool Cart::isCrashedWith(const Cart& c2) const {
    if(x == c2.x && y == c2.y) return true;
    return false;
}

void Day13::run(int part) {
    std::vector<std::string> tracks = AoCDay::readFileLines("inputs/day13.txt");
    std::vector<Cart> carts;
    
    for(int i = 0; i < tracks.size(); i++) {
        for(int j = 0; j < tracks[i].length(); j++) {
            if(tracks[i][j] == '^' || tracks[i][j] == 'v') {
                carts.push_back(Cart(j, i, tracks[i][j]));
                tracks[i][j] = '|';
            } else if(tracks[i][j] == '<' || tracks[i][j] == '>') {
                carts.push_back(Cart(j, i, tracks[i][j]));
                tracks[i][j] = '-';
            }
        }
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        while(true) {
            for(int c = 0; c < carts.size(); c++) {
                carts[c].advance();
                if(tracks[carts[c].y][carts[c].x] == '+')
                    carts[c].turn();
                else if(tracks[carts[c].y][carts[c].x] == '/' || tracks[carts[c].y][carts[c].x] == '\\')
                    carts[c].turnCorner(tracks[carts[c].y][carts[c].x]);
                
                for(int c2 = 0; c2 < carts.size(); c2++) {
                    if(c2 != c && carts[c].isCrashedWith(carts[c2])){
                        std::cout << "Answer: " << carts[c].x << "," << carts[c].y << std::endl;
                        return;
                    }
                }
            }
        }
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::vector<Cart> safeCarts;
        while(carts.size() != 1) {
            safeCarts.clear();
            for(int c = 0; c < carts.size(); c++) {
                carts[c].advance();
                if(tracks[carts[c].y][carts[c].x] == '+')
                    carts[c].turn();
                else if(tracks[carts[c].y][carts[c].x] == '/' || tracks[carts[c].y][carts[c].x] == '\\')
                    carts[c].turnCorner(tracks[carts[c].y][carts[c].x]);
                
                for(int c2 = 0; c2 < carts.size(); c2++) {
                    if(c2 != c && carts[c].isCrashedWith(carts[c2])){
                        carts[c].crashed = true;
                        carts[c2].crashed = true;
                    }
                }
            }
            
            for(const Cart& c: carts)
                if(!c.isCrashed()) safeCarts.push_back(c);
            carts = safeCarts;
        }
        
        std::cout << "Answer: " << carts[0].x << "," << carts[0].y << std::endl;
        
    }
    
}

