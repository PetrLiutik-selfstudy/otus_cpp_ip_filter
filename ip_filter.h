#pragma once

#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

using ip_addr_t = std::array<int, 4>;
using ip_pool_t = std::vector<ip_addr_t>;

// Формирование пула IP-адресов из входного потока.
ip_pool_t FormIpPool(std::istream& inputStream);
