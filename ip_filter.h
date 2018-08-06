#pragma once

#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

constexpr size_t IP_ELEMS = 4;

using ip_addr_t = std::array<int, IP_ELEMS>;
using ip_pool_t = std::vector<ip_addr_t>;

// Формирование пула IP-адресов из входного потока.
ip_pool_t FormIpPool(std::istream& inputStream);

// Вывод пула IP-адресов в выходной поток.
void PrintIpPool(const ip_pool_t& ipPool, std::ostream& outputStream);

// Сортировка пула IP-адресов в обратном лексиграфическом порядке.
void SortIpPool(ip_pool_t& ipPool);

// Фильтрация по одному (первому) элементу IP-адреса.
ip_pool_t IpFilter(int addr, const ip_pool_t& ipPool);

// Фильтрация по первому и второму элементам IP-адреса.
ip_pool_t IpFilter(int addr1, int addr2, ip_pool_t& ipPool);

// Фильтрация по любому элементу IP-адреса.
ip_pool_t IpFilterAny(int addr, ip_pool_t& ipPool);
