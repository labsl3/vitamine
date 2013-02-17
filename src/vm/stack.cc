#include "stack.h"
#include <iostream>

namespace vitamine
{
  namespace vm
  {
    stack::stack()
    {

    }

    void stack::push(int p)
    {
      _stack.push(p);
    }

    int stack::pop()
    {
      int p = _stack.top();
      _stack.pop();
      return p;
    }
  }
}

