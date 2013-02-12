#include "vm.h"
#include "as/utils.h"

namespace vitamine
{
  namespace vm
  {
    vm::vm()
    {
    
    }
    
    void vm::run()
    {
      using namespace vitamine::as;

      /*
       * TODO : Find a scalable solution, template specialization? map of function?
       */
      for (size_t i = 0; i < execution.size(); i++)
      {
        if (execution[i] == PUSH)
        {
          i++;
          _stack.push(execution[i]);
        }
        else if (execution[i] == ADD)
        {
          int a = _stack.top();
          _stack.pop();
          int b = _stack.top();
          _stack.pop();

          _stack.push(a + b);
        }
        else if (execution[i] == SUB)
        {
          int a = _stack.top();
          _stack.pop();
          int b = _stack.top();
          _stack.pop();

          _stack.push(b - a);
        }
        else if (execution[i] == MUL)
        {
          int a = _stack.top();
          _stack.pop();
          int b = _stack.top();
          _stack.pop();

          _stack.push(a * b);
        }
        else if (execution[i] == DIV)
        {
          int a = _stack.top();
          _stack.pop();
          int b = _stack.top();
          _stack.pop();

          _stack.push(b / a);
        }
        else if (execution[i] == PRINT)
        {
          int a = _stack.top();
          _stack.pop();

          std::cout << a << std::endl;
        }
        else
        {
          // TODO
        }
      }
    }
  }
}

