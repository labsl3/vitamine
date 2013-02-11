#ifndef __ASM_ASSEMBLER_H
#define __ASM_ASSEMBLER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "utils.h"

namespace vitamine
{
  namespace as
  {
    //std::map<std::string, int> opcodes; 

    void fill_opcodes();

    std::vector<int> get_opcodes_from_instructions(const std::vector<std::string>&);
  }
}

#endif
