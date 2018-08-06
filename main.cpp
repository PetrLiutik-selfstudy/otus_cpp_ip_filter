#include <iostream>
#include "ver.h"
#include "ip_filter.h"
#include <fstream>



int main(int argc, char const *argv[]) {
  ip_pool_t ipPool = FormIpPool(std::cin);

  SortIpPool(ipPool);
  PrintIpPool(ipPool, std::cout);

  PrintIpPool(IpFilter(1, ipPool), std::cout);
  PrintIpPool(IpFilter(46, 70, ipPool), std::cout);
  PrintIpPool(IpFilterAny(46, ipPool), std::cout);

  return 0;
}
