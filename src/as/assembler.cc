#include "assembler.h"
#include "utils.h"

namespace vitamine
{
  namespace as
  {

    std::map<std::string, int> opcodes;

    void fill_opcodes()
    {
      /* 0x1 -> 0x9 : reserved */

      opcodes["push"]   = PUSH;
      opcodes["add"]    = ADD;
      opcodes["sub"]    = SUB;
      opcodes["mul"]    = MUL;
      opcodes["div"]    = DIV;
      opcodes["print"]  = PRINT;
    }
   
    std::vector<int> get_opcodes_from_instructions(const std::vector<std::string>& insts)
    {
      std::vector<int> ops;

      for (auto i : insts)
      {
        if (is_instruction(i))
        {
          ops.push_back(opcodes[i]);
        }
        else if (is_number(i))
          ops.push_back(std::atoi(i.c_str()));
      }

      return ops;
    }
  }
}
