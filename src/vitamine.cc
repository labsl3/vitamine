#include "vitamine.h"
#include "as/assembler.h"

namespace vitamine
{
  vitamine::vitamine(const std::string& file_name)
    : _file_name(file_name)
  {
    as::fill_opcodes();
  }
  
  void vitamine::operator()()
  {
    run();
  }

  void vitamine::run()
  {
    auto ints = fs::get_instructions_from_file(_file_name); 
    auto flow = as::get_opcodes_from_instructions(ints);
  }
}

