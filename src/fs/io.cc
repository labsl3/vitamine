#include "io.h"

namespace vitamine
{
  namespace fs
  {
    std::vector<std::string> get_instructions_from_file(const std::string& file_name)
    {
      std::vector<std::string> instructions;

      std::ifstream file(file_name.c_str());

      if (file)
      {
        /*
         * read the whole content of the file and put it in a buffer
         */
        std::stringstream buffer(std::stringstream::in | std::stringstream::out);

        // delete comments
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line))
        {
          lines.push_back(line);
        }

        for (auto& l : lines)
        {
          // find the ; 
          auto it = std::find(l.begin(), l.end(), ';');
          // if exists
          if (it != l.end())
            // erase from ; to end
            l.erase(it, l.end());
          
          // add to buffer
          buffer << l << "\n";
        }

        /*
         * read the buffer and insert instructions in a vector
         */
        std::copy(std::istream_iterator<std::string>(buffer),
            std::istream_iterator<std::string>(),
            std::back_inserter<std::vector<std::string>>(instructions));
      }

      return instructions;
    }
  }
}
