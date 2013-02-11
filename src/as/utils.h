#ifndef __ASM_UTILS_H
#define __ASM_UTILS_H

#include <string>
#include <algorithm>
#include <functional>

namespace vitamine
{
  namespace as
  {
    bool is_instruction(const std::string& s);
    bool is_number(const std::string& s);

    enum { PUSH = 0xa, ADD, SUB, MUL, DIV, PRINT };
  }
}

#endif
