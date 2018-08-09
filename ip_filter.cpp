#include "ip_filter.h"
#include <algorithm>
#include <iterator>

/**
 * @brief Разбивка строки на подстроки.
 * @param str - строка.
 * @param delim - разделитель.
 * @return
 */
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

      ipPool.emplace_back(ipAddr);
    }

    // Чтение до конца строки.
    std::getline(inputStream, str);
  }
  return ipPool;
}

void SortIpPool(ip_pool_t& ipPool) {
  std::sort(ipPool.begin(), ipPool.end(), [](const ip_addr_t& ip1, const ip_addr_t& ip2){
    auto it1   = ip1.begin();
    auto last1 = ip1.end();
    auto it2   = ip2.begin();
    auto last2 = ip2.end();
    for ( ; (it2 != last2) && (it1 != last1); ++it2, ++it1 ) {
        if (*it2 < *it1) return true;
        if (*it1 < *it2) return false;
    }
    return (it2 == last2) && (it1 != last1);
  });
}

/**
 * @brief Собственно сама фильтрация.
 * @param ipPool - пул IP-адресов.
 * @param matchFunc - лямбда-функция проверки соответсвия IP-адреса.
 * @return
 */
template <typename T>
ip_pool_t IpFilter(const ip_pool_t& ipPool, T matchFunc) {
  ip_pool_t ipPoolFiltered;
  ipPoolFiltered.reserve(ipPool.size());
  for(const auto& it: ipPool) {
    if(matchFunc(it))
      ipPoolFiltered.emplace_back(it);
  }
  ipPoolFiltered.shrink_to_fit();
  return ipPoolFiltered;
}

ip_pool_t IpFilter(int addr, const ip_pool_t& ipPool) {
  auto matchFunc = [addr](const auto& ip){ return ip[0] == addr; };
  return IpFilter(ipPool, matchFunc);
}

ip_pool_t IpFilter(int addr1, int addr2, ip_pool_t& ipPool) {
  auto matchFunc = [addr1, addr2](auto& ip){ return ip[0] == addr1 && ip[1] == addr2; };
  return IpFilter(ipPool, matchFunc);
}

ip_pool_t IpFilterAny(int addr, ip_pool_t& ipPool) {
  auto matchFunc = [addr](auto& ip){
    return ip[0] == addr || ip[1] == addr || ip[2] == addr || ip[3] == addr;
  };
  return IpFilter(ipPool, matchFunc);
}

void PrintIpPool(const ip_pool_t& ipPool, std::ostream& outputStream) {
  for(const auto& it: ipPool) {
    outputStream << it[0] << ".";
    outputStream << it[1] << ".";
    outputStream << it[2] << ".";
    outputStream << it[3];
    outputStream << std::endl;
  }
}
