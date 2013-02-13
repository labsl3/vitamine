#ifndef __VM_VM_H
#define __VM_VM_H

#include <iostream>

#include "stack.h"
#include "flow.h"
#include "process.h"

namespace vitamine
{
  namespace vm
  {
    class vm
    {
      public:
        vm();
        
        // run execution
        void run();

        // execution flow
        vitamine::vm::flow flow; 

      protected:

        // memory stack
        vitamine::vm::stack _stack;
        vitamine::vm::process _process;
 
    };
  }
}

#endif

