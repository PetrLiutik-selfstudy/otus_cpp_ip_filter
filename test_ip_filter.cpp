#include <iostream>
#include <sstream>
#include "gtest/gtest.h"
#include "ver.h"
#include "ip_filter.h"

TEST(ver_test_case, ver_major_test) {
  EXPECT_GE(ver_major(), 1);
}

TEST(ver_test_case, ver_minor_test) {
  EXPECT_GE(ver_minor(), 1);
}

TEST(ver_test_case, ver_patch_test) {
  EXPECT_GE(ver_patch(), 1);
}

TEST(ip_filter_test_case, ip_form_pool) {
  std::stringstream iss;

  iss << "5.189.203.79\t30\t0\n"   <<
         "197.42.2.124\tabcd\n"    <<
         "95.10.3.43\t72\t0\n"     <<
         "180.251.148.71\t1\t0\n"  <<
         "113.144.6.220\t6\t0\n"   <<
         "89.236.227.204\t0\t1\n"  <<
         "67.250.31.212\t1\t0\n"   <<
         "67.250.31.212\t1\t0\n"   <<
         "177.66.186.82\tololo\n"  <<
         "107.209.121.224\t2\t0\n" <<
         "213.103.211.108\t0\t2\n" <<
         "27.49.172.153\t0\t3\n"   <<
         "78.158.5.183\t0\t1\n"    <<
         "78.158.5.183\t0\t1\n"    <<
         "27.109.142.224\t0\t4\n"  <<
         "103..109.70\t0\t4\n"     <<
         "117.241..153\t2\t4\n"    <<
         "..190.166\t1\t0\n"       <<
         "...11\t1\t0\n"           <<
         "a.1.70.220\t0\t1\n"      <<
         "a.b.117.72\t25\t0\n"     <<
         "a.b.c.128\t0\t4\n"       <<
         "a.b.c.d\t278\t0\n"       <<
         ".\t24\t0\n";

  ip_pool_t result{{5,   189, 203, 79},
                   {197, 42,  2,   124},
                   {95,  10,  3,   43},
                   {180, 251, 148, 71},
                   {113, 144, 6,   220},
                   {89,  236, 227, 204},
                   {67,  250, 31,  212},
                   {67,  250, 31,  212},
                   {177, 66,  186, 82},
                   {107, 209, 121, 224},
                   {213, 103, 211, 108},
                   {27,  49,  172, 153},
                   {78,  158, 5,   183},
                   {78,  158, 5,   183},
                   {27,  109, 142, 224}};

  EXPECT_EQ(FormIpPool(iss), result);
}

TEST(ip_filter_test_case, ip_sort) {
  std::vector<ip_addr_t> input {{68,  202, 216, 62},
                                {5,   189, 203, 79},
                                {197, 42,  2,   124},
                                {95,  10,  3,   43},
                                {180, 251, 148, 71}};

  const std::vector<ip_addr_t> result {{197, 42,  2,   124},
                                       {180, 251, 148, 71},
                                       {95,  10,  3,   43},
                                       {68,  202, 216, 62},
                                       {5,   189, 203, 79}};

  SortIpPool(input);

  EXPECT_EQ(input, result);                                     
}

TEST(ip_filter_test_case, ip_filter_firts_elem) {
  std::vector<ip_addr_t> input {{197, 42,  2,   124},
                                {180, 251, 148, 71},
                                {180,  10,  3,  43},
                                {68,  202, 216, 62},
                                {5,   189, 203, 79}};

  const std::vector<ip_addr_t> result {{180, 251, 148, 71}};

  EXPECT_EQ(IpFilter(180, 251, input), result);
}

TEST(ip_filter_test_case, ip_filter_firts_second_elems) {
  std::vector<ip_addr_t> input {{197, 42,  2,   124},
                                {180, 251, 148, 71},
                                {180,  10,  3,  43},
                                {68,  202, 216, 62},
                                {5,   189, 203, 79}};

  const std::vector<ip_addr_t> result {{180, 251, 148, 71},
                                       {180,  10,  3,   43}};

  EXPECT_EQ(IpFilter(180,  input), result);
}

TEST(ip_filter_test_case, ip_filter_any) {
  std::vector<ip_addr_t> input {{197, 42,  2,   202},
                                {180, 251, 202, 71},
                                {95,  10,  3,   43},
                                {68,  202, 216, 62},
                                {202, 5,   71,  87},
                                {5,   189, 203, 79}};

  const std::vector<ip_addr_t> result {{197, 42,  2,   202},
                                       {180, 251, 202, 71},
                                       {68,  202, 216, 62},
                                       {202, 5,   71,  87}};

  EXPECT_EQ(IpFilterAny(202, input), result);
}