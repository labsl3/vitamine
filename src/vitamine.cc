#include "vitamine.h"
#include "as/assembler.h"

namespace vitamine
{
  vitamine::vitamine(const std::string& file_name)
    : _virtual_machine(),
       _file_name(file_name)
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
    auto opcodes = as::get_opcodes_from_instructions(ints);

    _virtual_machine.flow.opcodes = opcodes;
    _virtual_machine.run();
  }
}

