#ifndef __VM_VM_H
#define __VM_VM_H

#include <iostream>
#include <vector>
#include <stack>

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
        std::vector<int> execution;

      protected:

        // memory stack
        std::stack<int> _stack;

        
    };
  }
}

#endif

