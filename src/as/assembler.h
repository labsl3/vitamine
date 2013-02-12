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
    /*
     * Fill the opcodes map
     */
    void fill_opcodes();

    /*
     * Parse instructions and return opcodes
     */
    std::vector<int> get_opcodes_from_instructions(const std::vector<std::string>&);
  }
}

#endif
