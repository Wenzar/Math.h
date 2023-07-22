#include "my_math_test.h"

START_TEST(test1) {
  double x = 1233257678;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test2) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test3) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test4) {
  double x = 2147483647;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test7) {
  double x = 7.3445e-29;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}

START_TEST(test8) {
  double x = -0.766787;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}

START_TEST(test5) {
  double x = -3313.567;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_exp(x));
}
END_TEST

START_TEST(test10) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = INFINITY;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test12) {
  double x = -INFINITY;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test13) {
  double x = 1e16;
  ck_assert_ldouble_eq(exp(x), my_exp(x));
}
END_TEST

START_TEST(test14) {
  double x = 1e-16;
  ck_assert_ldouble_eq_tol(exp(x), my_exp(x), 1e-6);
}
END_TEST

Suite *exp_suite(void) {
  Suite *test_suite = suite_create("exp_suite");
  TCase *test_case = tcase_create("exp_case");

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
  tcase_add_test(test_case, test13);
  tcase_add_test(test_case, test14);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}