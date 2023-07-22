#include "my_math_test.h"

START_TEST(test1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = 0.123456;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = 987565.9874641213656;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = MY_PI / 3;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test7) {
  double x = MY_PI / 6;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = MY_PI / 2;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = 2 * MY_PI / 3;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = 5 * MY_PI / 6;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test12) {
  double x = MY_PI;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = -15.24534567;
  ck_assert_ldouble_nan(my_sqrt(x));
}
END_TEST

START_TEST(test13) {
  double x = 634.41;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test14) {
  double x = 12345634789;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test15) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}

START_TEST(test16) {
  double x = 4.435e-34;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test17) {
  double x = 1e-16;
  ck_assert_ldouble_eq_tol(sqrt(x), my_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test18) {
  double x = -121.456;
  ck_assert_ldouble_nan(my_sqrt(x));
}
END_TEST

START_TEST(test19) {
  double x = -2435345643674376437.8673412432142142149;
  ck_assert_ldouble_nan(my_sqrt(x));
}
END_TEST

START_TEST(test20) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_sqrt(x));
}
END_TEST

START_TEST(test21) {
  double x = INFINITY;
  ck_assert_ldouble_eq(sqrt(x), my_sqrt(x));
}
END_TEST

START_TEST(test22) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(my_sqrt(x));
}
END_TEST

START_TEST(test23) {
  double x[5] = {1.0, MY_PI / 2, 2 * MY_PI / 3, 5 * MY_PI / 6, MY_PI};
  int i = _i;
  ck_assert_ldouble_eq_tol(sqrt(x[i]), my_sqrt(x[i]), 1e-6);
}
END_TEST

Suite *sqrt_suite(void) {
  Suite *test_suite = suite_create("sqrt_suite");
  TCase *test_case = tcase_create("sqrt_case");

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
  tcase_add_test(test_case, test16);
  tcase_add_test(test_case, test17);
  tcase_add_test(test_case, test18);
  tcase_add_test(test_case, test19);
  tcase_add_test(test_case, test20);
  tcase_add_test(test_case, test21);
  tcase_add_test(test_case, test22);
  tcase_add_loop_test(test_case, test23, 0, 5);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}