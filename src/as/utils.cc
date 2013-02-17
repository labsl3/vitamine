#include "utils.h"

namespace vitamine
{
  namespace as
  {
    bool is_label(const std::string& s)
    {
      return s[s.size() - 1] == ':';
    }

    bool is_instruction(const std::string& s)
    {
      return !s.empty() && std::find_if(s.begin(), 
        s.end(), [=](char c) { return !std::isalpha(c); }) == s.end();
    }

    bool is_number(const std::string& s)
    {
      return !s.empty() && std::find_if(s.begin(), 
        s.end(), [=](char c) { return !std::isdigit(c); }) == s.end();
    }
  }
}
