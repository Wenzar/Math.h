#include "my_math_test.h"

START_TEST(test1) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = 5;
  ck_assert_ldouble_nan(my_asin(x));
}
END_TEST

START_TEST(test7) {
  double x = -5;
  ck_assert_ldouble_nan(my_asin(x));
}
END_TEST

START_TEST(test8) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = 1 + 1e-16l;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = -1 - 1e-16l;
  ck_assert_ldouble_eq_tol(asin(x), my_asin(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_asin(x));
}
END_TEST

START_TEST(test12) {
  double x = INFINITY;
  ck_assert_ldouble_nan(my_asin(x));
}
END_TEST

START_TEST(test13) {
  double x = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(i - x * i), my_ceil(i - x * i), 1e-6);
}
END_TEST

Suite *asin_suite(void) {
  Suite *test_suite = suite_create("asin_suite");
  TCase *test_case = tcase_create("asin_case");

  tcase_add_test(test_case, test1);
  tcase_add_test(test_case, test2);
  tcase_add_test(test_case, test3);
  tcase_add_test(test_case, test4);
  tcase_add_test(test_case, test5);
  tcase_add_test(test_case, test6);
  tcase_add_test(test_case, test7);
  tcase_add_test(test_case, test8);
  tcase_add_test(test_case, test9);
  tcase_add_test(test_case, test10);
  tcase_add_test(test_case, test11);
  tcase_add_test(test_case, test12);
  tcase_add_loop_test(test_case, test13, -MY_PI / 2, MY_PI / 2);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}