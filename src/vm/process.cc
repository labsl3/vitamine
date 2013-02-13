#include "process.h"
#include "as/utils.h"

using namespace vitamine::as;

namespace vitamine
{
  namespace vm
  {
    process::process(flow& flow, stack& stack)
      : _flow(flow),
        _stack(stack)
    {
      table[PUSH]   = &vitamine::vm::process::push; 
      table[ADD]    = &vitamine::vm::process::add; 
      table[SUB]    = &vitamine::vm::process::sub; 
      table[MUL]    = &vitamine::vm::process::mul; 
      table[DIV]    = &vitamine::vm::process::div; 
      table[PRINT]  = &vitamine::vm::process::print; 
    }

    void process::run(int opcode)
    {
      if (table[opcode])
        (this->*table[opcode])();
    }


    void process::push()
    {
      _stack.push(_flow.next());
    }

    void process::add()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(a + b);
    }

    void process::sub()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b - a);
    }

    void process::mul()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(a * b);
    }

    void process::div()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b / a);
    }

    void process::print()
    {
      int a = _stack.pop();

      std::cout << a << std::endl;
    }



  }
}
