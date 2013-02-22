#ifndef __FS_IO_H
#define __FS_IO_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <regex>
#include <iostream>

namespace vitamine
{
  namespace fs
  {
    /*
     * retrieve instructions from a file
     */
    std::vector<std::string> get_instructions_from_file(const std::string&);
  }
}

#endif
