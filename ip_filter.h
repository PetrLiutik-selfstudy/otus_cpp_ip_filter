#pragma once

#include <array>
#include <vector>
#include <memory>
#include <sstream>

const size_t IP_ELEMS = 4;

/**
 * @brief Тип IP-адреса.
 */
using ip_addr_t = std::array<int, IP_ELEMS>;

/**
 * @brief Тип пула IP-адресов.
 */
using ip_pool_t = std::vector<ip_addr_t>;

/**
 * @brief Формирование пула IP-адресов из входного потока.
 * @param inputStream - входной поток.
 * @return пул IP-адресов.
 */
ip_pool_t FormIpPool(std::istream& inputStream);

/**
 * @brief Вывод пула IP-адресов в выходной поток.
 * @param ipPool - пул IP-адресов.
 * @param outputStream - выходной поток.
 */
void PrintIpPool(const ip_pool_t& ipPool, std::ostream& outputStream);

/**
 * @brief Сортировка пула IP-адресов в обратном лексиграфическом порядке.
 * @param ipPool - пул IP-адресов.
 */
void SortIpPool(ip_pool_t& ipPool);

/**
 * @brief Фильтрация по одному (первому) элементу IP-адреса.
 * @param addr - первый элемент IP-адреса.
 * @param ipPool - пул IP-адресов.
 * @return отфильтрованный пул IP-адресов.
 */
ip_pool_t IpFilter(int addr, const ip_pool_t& ipPool);

/**
 * @brief Фильтрация по первому и второму элементам IP-адреса.
 * @param addr1 - первый элемент IP-адреса.
 * @param addr2 - второй элемент IP-адреса.
 * @param ipPool - пул IP-адресов.
 * @return отфильтрованный пул IP-адресов.
 */
ip_pool_t IpFilter(int addr1, int addr2, ip_pool_t& ipPool);

/**
 * @brief Фильтрация по любому элементу IP-адреса.
 * @param addr - элемент IP-адреса.
 * @param ipPool - пул IP-адресов.
 * @return отфильтрованный пул IP-адресов.
 */
ip_pool_t IpFilterAny(int addr, ip_pool_t& ipPool);
