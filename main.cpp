#include <iostream>
#include "ver.h"
#include "ip_filter.h"

int main(int argc, char const *argv[])
{
  std::cout << "Version: " << ver_major() << "." << ver_minor() << "." << ver_patch() << std::endl;
  return 0;
}
