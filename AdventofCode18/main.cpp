//
//  main.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 01/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include <iostream>
#include "headers/Day1.h"
#include "headers/Day2.h"
#include "headers/Day3.h"
#include "headers/Day4.h"

int main() {
    std::cout << "-*-*-*-*Day 1*-*-*-*-" << std::endl;
    Day1::run(1);
    Day1::run(2);
    std::cout << "-*-*-*-*-*-*-*-*-*-*-\n" << std::endl;
    std::cout << "-*-*-*-*Day 2*-*-*-*-" << std::endl;
    Day2::run(1);
    Day2::run(2);
    std::cout << "-*-*-*-*-*-*-*-*-*-*-\n" << std::endl;
    std::cout << "-*-*-*-*Day 3*-*-*-*-" << std::endl;
    Day3::run(1);
    Day3::run(2);
    std::cout << "-*-*-*-*-*-*-*-*-*-*-\n" << std::endl;
    std::cout << "-*-*-*-*Day 4*-*-*-*-" << std::endl;
    Day4::run(1);
    Day4::run(2);
    std::cout << "-*-*-*-*-*-*-*-*-*-*-\n" << std::endl;
    
    return 0;
}
