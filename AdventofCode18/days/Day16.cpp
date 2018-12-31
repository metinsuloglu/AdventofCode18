//
//  Advent of Code 2018
//  Day 16: Chronal Classification
//
//  adventofcode.com
//
//  Metin Suloglu, Dec 2018
//

#include "../headers/Day16.h"

std::vector<int> Instruction::execute(std::vector<int> regs) {
    switch (opcode) {
        case addr:
            regs[C] = regs[A] + regs[B]; break;
        case addi:
            regs[C] = regs[A] + B; break;
        case mulr:
            regs[C] = regs[A] * regs[B]; break;
        case muli:
            regs[C] = regs[A] * B; break;
        case banr:
            regs[C] = regs[A] & regs[B]; break;
        case bani:
            regs[C] = regs[A] & B; break;
        case borr:
            regs[C] = regs[A] | regs[B]; break;
        case bori:
            regs[C] = regs[A] | B; break;
        case setr:
            regs[C] = regs[A]; break;
        case seti:
            regs[C] = A; break;
        case gtir:
            (A > regs[B]) ? regs[C] = 1 : regs[C] = 0; break;
        case gtri:
            (regs[A] > B) ? regs[C] = 1 : regs[C] = 0; break;
        case gtrr:
            (regs[A] > regs[B]) ? regs[C] = 1 : regs[C] = 0; break;
        case eqir:
            (A == regs[B]) ? regs[C] = 1 : regs[C] = 0; break;
        case eqri:
            (regs[A] == B) ? regs[C] = 1 : regs[C] = 0; break;
        case eqrr:
            (regs[A] == regs[B]) ? regs[C] = 1 : regs[C] = 0; break;
        default:
            break;
    }
    
    return regs;
}

void Instruction::reset() {
    opcode = na; A = 0; B = 0; C = 0;
}

void Day16::run(int part) {
    std::ifstream file("inputs/day16.txt", std::ios::in);
    std::vector<int> registers(4, 0);
    
    std::unordered_map<int, Opcode> realOpcodes;
    std::unordered_map<int, std::vector<Opcode>> possibleOpcodes;
    
    std::vector<Opcode> allOpcodes;
    for(int i = 0; i < 16; i++) {
        allOpcodes.clear();
        for(int j = 1; j <= 16; j++) allOpcodes.push_back(Opcode(j));
        possibleOpcodes[i] = allOpcodes;
    }
    
    int totalCount = 0, opcode;
    Instruction inst;
    std::vector<int> afterRegs(4);
    
    std::string before, instruction, after;
    std::vector<Opcode> workingOpcodes;
    while(true) {
        getline(file, before);
        if(before == "") break;
        getline(file, instruction); getline(file, after);
        file.seekg(1, file.cur);
        
        sscanf(before.c_str(), "Before: [%d, %d, %d, %d]", &registers[0], &registers[1], &registers[2], &registers[3]);
        sscanf(instruction.c_str(), "%d %d %d %d", &opcode, &inst.A, &inst.B, &inst.C);
        sscanf(after.c_str(), "After:  [%d, %d, %d, %d]", &afterRegs[0], &afterRegs[1], &afterRegs[2], &afterRegs[3]);
        
        workingOpcodes.clear();
        for(int op = 1; op <= 16; op++) {
            inst.opcode = Opcode(op);
            std::vector<int> finalRegs = inst.execute(registers);
            if(finalRegs == afterRegs) workingOpcodes.push_back(inst.opcode);
        }
        
        if(workingOpcodes.size() >= 3) totalCount++;
        
        std::sort(workingOpcodes.begin(), workingOpcodes.end());
        std::sort(possibleOpcodes[opcode].begin(), possibleOpcodes[opcode].end());
        
        std::vector<Opcode> matchedOpcodes;
        std::set_intersection(possibleOpcodes[opcode].begin(), possibleOpcodes[opcode].end(), workingOpcodes.begin(), workingOpcodes.end(), std::back_inserter(matchedOpcodes));
        possibleOpcodes[opcode] = matchedOpcodes;
        
        inst.reset();
    }
    
    if(part == 1) {
        std::cout << "~Part 1~" << std::endl;
        
        std::cout << "Answer: " << totalCount << std::endl;
        
    } else {
        std::cout << "~Part 2~" << std::endl;
        
        std::fill(registers.begin(), registers.end(), 0);
        inst.reset();
        
        while(realOpcodes.size() < 16) {
            for(auto& [op, possibleOps]: possibleOpcodes) {
                if(possibleOps.size() == 1) {
                    realOpcodes[op] = possibleOps[0];
                    for(auto& [otherOp, otherPossibleOps]: possibleOpcodes) {
                        if(otherOp != op)
                            otherPossibleOps.erase(std::remove(otherPossibleOps.begin(), otherPossibleOps.end(), realOpcodes[op]), otherPossibleOps.end());
                    }
                }
            }
        }
        
        std::string instruction;
        while(getline(file, instruction)) {
            sscanf(instruction.c_str(), "%d %d %d %d", &opcode, &inst.A, &inst.B, &inst.C);
            inst.opcode = realOpcodes[opcode];
            registers = inst.execute(registers);
        }
        
        std::cout << "Answer: " << registers[0] << std::endl;
    }
}

