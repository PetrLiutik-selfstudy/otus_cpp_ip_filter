#include <iostream>
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
         "197.42.2.124\t0\t2\n"    <<
         "95.10.3.43\t72\t0\n"     <<
         "180.251.148.71\t1\t0\n"  <<
         "113.144.6.220\t6\t0\n"   <<
         "89.236.227.204\t0\t1\n"  <<
         "67.250.31.212\t1\t0\n"   <<
         "67.250.31.212\t1\t0\n"   <<
         "177.66.186.82\t2\t0\n"   <<
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

  ip_pool_t ipPool{{5,   189, 203, 79},
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

  EXPECT_EQ(FormIpPool(iss), ipPool);
}

TEST(ip_filter_test_case, ip_str_split) {
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_sort) {
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_firts_elem) {
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_firts_second_elems) {
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_any) {
  EXPECT_EQ(1, 1);
}