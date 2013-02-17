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
      table[POP]    = &vitamine::vm::process::pop;
      table[ADD]    = &vitamine::vm::process::add; 
      table[SUB]    = &vitamine::vm::process::sub; 
      table[MUL]    = &vitamine::vm::process::mul; 
      table[DIV]    = &vitamine::vm::process::div; 
      table[PRINT]  = &vitamine::vm::process::print;
      table[AND]    = &vitamine::vm::process::_and;
      table[OR]     = &vitamine::vm::process::_or;
      table[XOR]    = &vitamine::vm::process::_xor;
      table[SHL]    = &vitamine::vm::process::shl;
      table[SHR]    = &vitamine::vm::process::shr;
      table[CMP]    = &vitamine::vm::process::cmp; 
      table[JMP]    = &vitamine::vm::process::jmp; 
      table[DPL]    = &vitamine::vm::process::duplicate; 
      table[JE]     = &vitamine::vm::process::jmp_if_equal;
      table[JNE]    = &vitamine::vm::process::jmp_if_not_equal;
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

    void process::pop()
    {
      _stack.pop();
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

    void process::_and()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b & a);
    }

    void process::_or()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b | a);
    }

    void process::_xor()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b ^ a);
    }

    void process::shl()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b << a);
    }

    void process::shr()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(b >> a);
    }

    void process::cmp()
    {
      int a = _stack.pop();
      int b = _stack.pop();

      _stack.push(a == b);
    }

    void process::jmp()
    {
      int distance = _flow.next();
      _flow.go_to(distance);
    }

    void process::jmp_if_equal()
    {
      int b = _stack.pop();

      if (b)
        jmp();
    }

    void process::jmp_if_not_equal()
    {
      int b = _stack.pop();

      if (!b)
        jmp();
    }

    void process::duplicate()
    {
      int a = _stack.pop();

      _stack.push(a);
      _stack.push(a);
    }
  }
}
