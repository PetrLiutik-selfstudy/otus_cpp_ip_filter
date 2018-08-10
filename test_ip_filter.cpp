#include <iostream>
#include "gtest/gtest.h"
#include "ver.h"
#include "ip_filter.h"

TEST(ver_test_case, ver_major_test)
{
  EXPECT_GE(ver_major(), 1);
}

TEST(ver_test_case, ver_minor_test)
{
  EXPECT_GE(ver_minor(), 1);
}

TEST(ver_test_case, ver_patch_test)
{
  EXPECT_GE(ver_patch(), 1);
}

TEST(ip_filter_test_case, ip_form_pool)
{
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_str_split)
{
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_sort)
{
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_firts_elem)
{
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_firts_second_elems)
{
  EXPECT_EQ(1, 1);
}

TEST(ip_filter_test_case, ip_filter_any)
{
  EXPECT_EQ(1, 1);
}