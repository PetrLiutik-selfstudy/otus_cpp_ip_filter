#include "ip_filter.h"

constexpr size_t IP_ELEMS = 4;

// Разбивка строки на подстроки.
std::vector<std::string> Split(const std::string &str, char delim) {

  std::vector<std::string> result;

  std::string::size_type start = 0;
  std::string::size_type stop  = str.find_first_of(delim);
  while(stop != std::string::npos) {
    result.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop  = str.find_first_of(delim, start);
  }

  result.push_back(str.substr(start));

  return result;
}

ip_pool_t FormIpPool(std::istream& inputStream) {
  ip_pool_t ipPool;

  for (std::string str; std::getline(inputStream, str, '\t'); ) {

    std::vector<std::string> splitStr = Split(str, '.');

    if(splitStr.size() == IP_ELEMS) {
      ip_addr_t ipAddr;
      std::size_t j = 0;
      for(auto it: splitStr)
        ipAddr[j++] = std::stoi(it);

      ipPool.push_back(ipAddr);
    }

    // Чтение до конца строки.
    std::getline(inputStream, str);
  }
  return ipPool;
}

