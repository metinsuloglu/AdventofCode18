//
//  AoCDay.cpp
//  AdventofCode18
//
//  Created by Metin Suloglu on 01/12/2018.
//  Copyright © 2018 Metin Suloglu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>

class AoCDay {
public:
    static std::string readFileAsString(const std::string& fileName) {
        std::ifstream in(fileName, std::ios::in);
        std::string readString = "";
        std::ostringstream fileText;
        fileText << in.rdbuf();
        in.close();
        readString = fileText.str();
        return readString;
    }
    
    static std::vector<std::string> readFileLines(const std::string& fileName) {
        std::ifstream file(fileName, std::ios::in);
        std::string line;
        std::vector<std::string> lines;
        while(getline(file, line))
            lines.push_back(line);
        return lines;
    }
};
