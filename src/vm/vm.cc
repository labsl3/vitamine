#include "vm.h"
#include "as/utils.h"

namespace vitamine
{
  namespace vm
  {
    vm::vm()
      : flow(),
        _stack(),
        _process(flow, _stack)
    {
    
    }
    
    void vm::run()
    {
      while (flow.hasNext())
      {
        // run current instruction
        _process.run(flow.current());

        // goes to next instruction
        flow.next();
      }
    }
  }
}

