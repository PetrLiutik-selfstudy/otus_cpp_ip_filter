#include <iostream>
#include "ver.h"
#include "ip_filter.h"



int main(int argc, char const *argv[]) {
  std::cout << "Version: " << ver_major() << "." << ver_minor() << "." << ver_patch() << std::endl;


  ip_pool_t ipPool = FormIpPool(std::cin);

  for(auto it: ipPool)
  {
    std::cout << "IP: ";
    for(auto it1: it)
    {
      std::cout << it1;
    }
    std::cout << std::endl;
  }

  return 0;
}
