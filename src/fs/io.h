#ifndef __FS_IO_H
#define __FS_IO_H

/**
 *  
 *
 *
 */

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>

namespace vitamine
{
  namespace fs
  {
    /*
     */
    std::vector<std::string> get_instructions_from_file(const std::string&);
  }
}

#endif
