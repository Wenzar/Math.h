#include "my_math_test.h"

START_TEST(test1) {
  double x = 3.3333333;
  double y = 4.0;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = 0.0;
  double y = 5.5;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = INFINITY;
  double y = 5.5;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test4) {
  double x = -INFINITY;
  double y = 5.5;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test5) {
  double x = 532456.83333;
  double y = 0.0;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test6) {
  double x = 0.8;
  double y = -0.0;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test7) {
  double x = 511112345.856890;
  double y = INFINITY;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = 5123421566.8666;
  double y = -INFINITY;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = MY_NAN;
  double y = 124.644;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test10) {
  double x = 5455.556;
  double y = MY_NAN;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test11) {
  double x = INFINITY;
  double y = MY_NAN;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST
START_TEST(test12) {
  double x = INFINITY;
  double y = 0.0;
  ck_assert_ldouble_nan(my_fmod(x, y));
}
END_TEST

START_TEST(test13) {
  double x = 3333333333333333.333333;
  double y = 4.0;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test14) {
  double x = 0.000333333;
  double y = 0.0554564415154657186;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(test15) {
  double x = -0.000333333;
  double y = -0.054657186;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

Suite *fmod_suite(void) {
  Suite *test_suite = suite_create("fmod_suite");
  TCase *test_case = tcase_create("fmod_case");

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
  tcase_add_test(test_case, test15);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}