#include <iostream>
#include "ver.h"
#include "ip_filter.h"
#include <fstream>



int main(int argc, char const *argv[]) {
  std::cout << "Version: " << ver_major() << "." << ver_minor() << "." << ver_patch() << std::endl;

  std::ifstream is ("ip_filter.tsv", std::ifstream::binary);

  ip_pool_t ipPool = FormIpPool(/*std::cin*/is);

  for(auto it: ipPool)
  {
    std::cout << "IP: ";
    for(auto it1: it)
      std::cout << it1 << ".";
    std::cout << std::endl;
  }

  return 0;
}
