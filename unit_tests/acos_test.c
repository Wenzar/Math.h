#include "my_math_test.h"

START_TEST(test1) {
  double x = 0.99999;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = -0.99999;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = -0.000001;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = 0.000001;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = 0;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_acos(x));
}
END_TEST

START_TEST(test7) {
  double x = INFINITY;
  ck_assert_ldouble_nan(my_acos(x));
}
END_TEST

START_TEST(test8) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(my_acos(x));
}
END_TEST

START_TEST(test9) {
  int i = _i;
  ck_assert_ldouble_eq_tol(acos(MY_PI * i), my_acos(MY_PI * i), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = 0.1234567894567890;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

START_TEST(test12) {
  ck_assert_ldouble_eq_tol(my_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(test13) {
  ck_assert_ldouble_eq_tol(my_acos(-sqrt(2) / 2), acos(-sqrt(2) / 2), 1e-6);
}
END_TEST

START_TEST(test14) {
  ck_assert_ldouble_eq_tol(my_acos(sqrt(2) / 2), acos(sqrt(2) / 2), 1e-6);
}
END_TEST

START_TEST(test15) {
  ck_assert_ldouble_eq_tol(my_acos(sqrt(3) / 2), acos(sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(test16) {
  double x = -1;
  ck_assert_ldouble_eq_tol(acos(x), my_acos(x), 1e-6);
}
END_TEST

Suite *acos_suite(void) {
  Suite *test_suite = suite_create("acos_suite");
  TCase *test_case = tcase_create("acos_case");

  tcase_add_test(test_case, test1);
  tcase_add_test(test_case, test2);
  tcase_add_test(test_case, test3);
  tcase_add_test(test_case, test4);
  tcase_add_test(test_case, test5);
  tcase_add_test(test_case, test6);
  tcase_add_test(test_case, test7);
  tcase_add_loop_test(test_case, test8, 0, 1);
  tcase_add_test(test_case, test9);
  tcase_add_test(test_case, test10);
  tcase_add_test(test_case, test11);
  tcase_add_test(test_case, test12);
  tcase_add_test(test_case, test13);
  tcase_add_test(test_case, test14);
  tcase_add_test(test_case, test15);
  tcase_add_test(test_case, test16);
  suite_add_tcase(test_suite, test_case);
  return test_suite;
}