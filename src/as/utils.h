#ifndef __ASM_UTILS_H
#define __ASM_UTILS_H

#include <string>
#include <algorithm>
#include <functional>

namespace vitamine
{
  namespace as
  {
    /*
     * OPCODES
     */
    enum { PUSH = 0xa, POP, ADD, SUB, MUL, DIV, PRINT, AND, OR, XOR, SHL, SHR, CMP };
    
    /*
     * locale functions
     */
    bool is_instruction(const std::string& s);
    bool is_number(const std::string& s);
  }
}

#endif
