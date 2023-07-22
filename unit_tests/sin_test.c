#include "my_math_test.h"

START_TEST(test1) {
  double x = 2.52323;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = -2.524213;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = 8333343389;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = -333229;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = 0;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_sin(x));
}
END_TEST

START_TEST(test7) {
  double x = INFINITY;
  ck_assert_ldouble_nan(my_sin(x));
}
END_TEST

START_TEST(test8) {
  int i = _i;
  if (i == 0) {
    ck_assert_ldouble_nan(my_sin(MY_PI / i));
  } else {
    ck_assert_ldouble_eq_tol(sin(MY_PI / i), my_sin(MY_PI / i), 1e-6);
  }
}
END_TEST

START_TEST(test9) {
  int i = _i;
  ck_assert_ldouble_eq_tol(sin(MY_PI * i), my_sin(MY_PI * i), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = 0.1234567894567890;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(sin(x), my_sin(x), 1e-6);
}
END_TEST

Suite *sin_suite(void) {
  Suite *test_suite = suite_create("sin_suite");
  TCase *test_case = tcase_create("sin_case");

  tcase_add_test(test_case, test1);
  tcase_add_test(test_case, test2);
  tcase_add_test(test_case, test3);
  tcase_add_test(test_case, test4);
  tcase_add_test(test_case, test5);
  tcase_add_test(test_case, test6);
  tcase_add_test(test_case, test7);
  tcase_add_loop_test(test_case, test8, -16, 16);
  tcase_add_loop_test(test_case, test9, -16, 16);
  tcase_add_test(test_case, test10);
  tcase_add_test(test_case, test11);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}