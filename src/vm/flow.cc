#include "flow.h"

namespace vitamine
{
  namespace vm
  {
    flow::flow()
      : _cursor(0)
    {

    }
    
    bool flow::hasNext()
    {
      return (unsigned int) _cursor < opcodes.size();
    }

    int flow::next()
    {
      ++_cursor;
      return current();
    }

    int flow::current()
    {
      return opcodes[_cursor];
    }

  }
}

