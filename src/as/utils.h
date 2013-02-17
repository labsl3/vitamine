#ifndef __ASM_UTILS_H
#define __ASM_UTILS_H

#include <string>
#include <algorithm>
#include <functional>
#include <map>

namespace vitamine
{
  namespace as
  {
    /*
     * OPCODES
     */
    enum { PUSH = 0xa, POP, ADD, SUB, MUL, DIV, PRINT, AND, OR, XOR, SHL, SHR, CMP, JMP, JE,
      JNE, DPL };

    /*
     */
        
    /*
     * locale functions
     */
    bool is_label(const std::string&);
    bool is_instruction(const std::string&);
    bool is_number(const std::string&);
  }
}

#endif
