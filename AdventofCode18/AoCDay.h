//
//  AoCDay.h
//  AdventofCode18
//
//  Created by Metin Suloglu on 02/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#ifndef AoCDay_h
#define AoCDay_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <unordered_set>
#include <regex>

class AoCDay {
public:
    static std::vector<std::string> readFileLines(const std::string& fileName);
    static std::string readFileAsString(const std::string& fileName);
};

#endif /* AoCDay_h */
