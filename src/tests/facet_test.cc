#include <gtest/gtest.h>

#include "../core/obj.h"

TEST(Facet_3d, operator_eq) {
  s21::Facet_3d f_1 = {{1, 2, 3}};
  s21::Facet_3d f_2 = {{1, 2, 3}};
  s21::Facet_3d f_3 = {{3, 2, 1}};

  ASSERT_TRUE(f_1 == f_2);
  ASSERT_FALSE(f_1 == f_3);

  std::vector<s21::Facet_3d> ff_1 = {f_1, f_3};
  std::vector<s21::Facet_3d> ff_2 = {f_2, f_3};
  std::vector<s21::Facet_3d> ff_3 = {f_3, f_1};

  ASSERT_TRUE(ff_1 == ff_2);
  ASSERT_FALSE(ff_1 == ff_3);
}
