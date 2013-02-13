#ifndef __VM_PROCESS_H
#define __VM_PROCESS_H

#include <iostream>
#include <functional>
#include <map>

#include "flow.h"
#include "stack.h"
#include "as/utils.h"

namespace vitamine
{
  namespace vm
  {
    class process
    {
      public:
        process(flow&, stack&);

        void run(int opcode); 

      protected:
      
        vitamine::vm::flow& _flow;
        vitamine::vm::stack& _stack;
       
        std::map<int, void(process::*)()> table; 
        
        void push();
        void add();
        void sub();
        void mul();
        void div();
        void print();
    };
  }
}

#endif
