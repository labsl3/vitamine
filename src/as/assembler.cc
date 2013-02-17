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
      opcodes["pop"]    = POP;
      opcodes["add"]    = ADD;
      opcodes["sub"]    = SUB;
      opcodes["mul"]    = MUL;
      opcodes["div"]    = DIV;
      opcodes["print"]  = PRINT;
      opcodes["and"]    = AND;
      opcodes["or"]     = OR;
      opcodes["xor"]    = XOR;
      opcodes["shl"]    = SHL;
      opcodes["shr"]    = SHR;
      opcodes["cmp"]    = CMP;
      opcodes["jmp"]    = JMP;
      opcodes["je"]     = JE;
      opcodes["jne"]    = JNE;
      opcodes["dpl"]    = DPL;
    }
   
    std::vector<int> get_opcodes_from_instructions(const std::vector<std::string>& insts)
    {
      std::vector<int> ops;

      // string = label, int = label number, int = index in code
      std::map<std::string, std::tuple<int, int>> label_map;

      int index = 0, label_number = 0;

      for (auto i : insts)
      {
        if (is_label(i))
        {
          if (label_map.find(i) != label_map.end())
          {
            std::get<1>(label_map[i]) = index;
          }
          else
          {
            label_map[i] = std::make_tuple(++label_number, index);
          }
        }
        else if (is_instruction(i))
        {
          // if it's a instruction
          if (opcodes[i])
          {
            ops.push_back(opcodes[i]);
          }
          // or it's a label
          else
          {
            // if we don't find the label, we add it
            if (label_map.find(i + ':') == label_map.end())
            { 
              label_map[i + ':'] = std::make_tuple(++label_number, 0);
            }

            ops.push_back(label_number);
          }
         
          index++;
        }
        else if (is_number(i))
        {
          ops.push_back(std::atoi(i.c_str()));

          index++;
        }
      }

      /**
       * Fetch opcodes and replace label numbers by distance from the jump to the label
       */
      for (unsigned int i = 0; i < ops.size(); i++)
      {
        if (ops[i] != JMP && ops[i] != JE && ops[i] != JNE)
          continue;

        i++;

        int lb = ops[i];

        // find the label
        auto label = std::find_if(label_map.begin(), label_map.end(),
            [=](const std::pair<std::string, std::tuple<int,int>>& p)
            {
              return std::get<0>(p.second) == lb;
            });

        // modify the distance
        if (label != label_map.end())
        {
          ops[i] = std::get<1>(label->second) - i - 1;  
        }
      }

      return ops;
    }
  }
}
