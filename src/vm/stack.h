#ifndef __VM_STACK_H
#define __VM_STACK_H

#include <stack>

namespace vitamine
{
  namespace vm
  {
    class stack
    {
      public:
        stack();
        
        void push(int i);
        int pop();

      protected:
        std::stack<int> _stack;

    };
  }
}

#endif

