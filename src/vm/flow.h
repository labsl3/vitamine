#ifndef __VM_FLOW_H
#define __VM_FLOW_H

#include <vector>

namespace vitamine
{
  namespace vm
  {
    class flow
    {
      public:
        flow();

        std::vector<int> opcodes;
        
        bool hasNext();
        int next(); 
        int current();

      protected:
        int _cursor;
    };
  }
}

#endif

