#include <iostream>

#include "vitamine.h"

int main(int argc, char* argv[])
{
  vitamine::vitamine v(argv[1]);
  v();
  
  return 0;
}

