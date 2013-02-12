#ifndef __VITAMINE_H
#define __VITAMINE_H

#include <iostream>
#include <string>
#include <sstream>

#include "fs/io.h" 

namespace vitamine
{
  class vitamine
  {
    public:
      vitamine(const std::string&);
      void operator()();

    protected:
      void run();

      std::string _file_name;
  };
}


#endif // __VITAMINE_H
