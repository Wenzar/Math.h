#include "my_math_test.h"

START_TEST(test1) {
  double x = 287.5823;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

START_TEST(test2) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

START_TEST(test3) {
  double x = 4.323e-66;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

START_TEST(test4) {
  double x = 1e-55;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

START_TEST(test5) {
  double x = -332.12000;
  ck_assert_ldouble_nan(my_log(x));
}

START_TEST(test6) {
  double x = 0.0;
  ck_assert_ldouble_infinite(my_log(x));
}

START_TEST(test7) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

START_TEST(test8) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_log(x));
}

START_TEST(test9) {
  double x = -MY_NAN;
  ck_assert_ldouble_nan(my_log(x));
}

START_TEST(test10) {
  double x = INFINITY;
  ck_assert_ldouble_infinite(my_log(x));
}

START_TEST(test11) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(my_log(x));
}

START_TEST(test12) {
  double x = 2.718281828459045;
  ck_assert_ldouble_eq_tol(log(x), my_log(x), 1e-6);
}

Suite *log_suite(void) {
  Suite *test_suite = suite_create("log_suite");
  TCase *test_case = tcase_create("log_case");

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

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}