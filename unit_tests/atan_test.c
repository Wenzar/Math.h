#include "my_math_test.h"

START_TEST(test1) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = 100000000.0;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test7) {
  double x = -1000000000000000;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = 0.923456789012345678901234567890;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_atan(x));
}
END_TEST

START_TEST(test10) {
  double x = INFINITY;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = -INFINITY;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test12) {
  double i = _i;
  ck_assert_ldouble_eq_tol(atan(i / 20.0), my_atan(i / 20.0), 1e-6);
}
END_TEST

START_TEST(test13) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test14) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test15) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

START_TEST(test16) {
  double x = MY_PI / 2;
  ck_assert_ldouble_eq_tol(atan(x), my_atan(x), 1e-6);
}
END_TEST

Suite *atan_suite(void) {
  Suite *test_suite = suite_create("atan_suite");
  TCase *test_case = tcase_create("atan_case");

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
  tcase_add_loop_test(test_case, test12, -16, 16);
  tcase_add_test(test_case, test13);
  tcase_add_test(test_case, test14);
  tcase_add_test(test_case, test15);
  tcase_add_test(test_case, test16);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}