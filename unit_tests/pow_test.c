#include "my_math_test.h"

START_TEST(test1) {
  double x[3] = {134.5, 563.23, 33534.4};
  double power[3] = {1.4, 20.5e-34, -34.33345};
  int i = _i;
  for (int inner_i = 0; inner_i < 3; inner_i++) {
    ck_assert_ldouble_eq_tol(pow(x[inner_i], power[i]),
                             my_pow(x[inner_i], power[i]), 1e-6);
  }
}
END_TEST

START_TEST(test3) {
  double x = 563.23;
  double power = -42.;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = -150.145678;
  double power = -3.;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test5) {
  double x = -150.1;
  double power = 2.;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = -10.1;
  double power = -1.5;
  ck_assert_ldouble_nan(my_pow(x, power));
}
END_TEST

START_TEST(test7) {
  double x = 10.1;
  double power = 0.123;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = -27.45;
  double power = 1.0 / 3.0;
  ck_assert_ldouble_nan(my_pow(x, power));
}
END_TEST

START_TEST(test9) {
  double x = DBL_MAX;
  double power = -10;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = 1e-20;
  double power = 0.10;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = 0.34;
  double power = 11;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test12) {
  double x = 0;
  double power = -12;
  ck_assert_ldouble_infinite(my_pow(x, power));
}

START_TEST(test13) {
  double x = 0;
  double power = 12;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}

START_TEST(test14) {
  double x = -1;
  ck_assert_ldouble_eq_tol(pow(x, INFINITY), my_pow(x, INFINITY), 1e-6);
}

START_TEST(test15) {
  double x = 0.123;
  double power = -INFINITY;
  ck_assert_ldouble_infinite(my_pow(x, power));
}
END_TEST

START_TEST(test16) {
  double x = 0.123;
  double power = INFINITY;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test17) {
  double x = 13;
  double power = -INFINITY;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test18) {
  double x = -0.0;
  double power = 12;
  ck_assert_ldouble_eq(pow(x, power), my_pow(x, power));
}
END_TEST

START_TEST(test19) {
  double x = 13;
  double power = INFINITY;
  ck_assert_ldouble_infinite(my_pow(x, power));
  ck_assert_ldouble_infinite(pow(x, power));
}
END_TEST

START_TEST(test20) {
  double x = INFINITY;
  double power = -12;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test21) {
  double x = -INFINITY;
  double power = -13;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test22) {
  double x = -INFINITY;
  double power = 13;
  ck_assert_ldouble_infinite(my_pow(x, power));
  ck_assert_ldouble_infinite(pow(x, power));
}
END_TEST

START_TEST(test23) {
  double x = -INFINITY;
  double power = -12;
  ck_assert_ldouble_eq_tol(pow(x, power), my_pow(x, power), 1e-6);
}
END_TEST

START_TEST(test24) {
  double x = INFINITY;
  double power = 12;
  ck_assert_ldouble_infinite(my_pow(x, power));
  ck_assert_ldouble_infinite(pow(x, power));
}
END_TEST

START_TEST(test25) {
  double x[10] = {1.12,      -34.45, MY_NAN, -MY_NAN, INFINITY,
                  -INFINITY, 12,     -12,    13,      -13};
  double power = 0;
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(x[i], power), my_pow(x[i], power), 1e-6);
}
END_TEST

START_TEST(test26) {
  double x = 1.0;
  double power[11] = {1,         1.22233, -1.24563, MY_NAN, -MY_NAN, INFINITY,
                      -INFINITY, 12,      -12,      13,     -13};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(x, power[i]), my_pow(x, power[i]), 1e-6);
}
END_TEST

START_TEST(test27) {
  double x[6] = {1.1332, -32224.4333445, MY_NAN, -MY_NAN, INFINITY, -INFINITY};
  double power = MY_NAN;
  int i = _i;
  ck_assert_ldouble_nan(my_pow(x[i], power));
}
END_TEST

START_TEST(test28) {
  double x = MY_NAN;
  double power[6] = {1, -1, -1111.1, 11.11111, MY_NAN, -MY_NAN};
  int i = _i;
  ck_assert_ldouble_nan(my_pow(x, power[i]));
  ck_assert_ldouble_nan(pow(x, power[i]));
}
END_TEST

START_TEST(test29) {
  double x[6] = {1.1562, -34.33345, MY_NAN, -MY_NAN, INFINITY, -INFINITY};
  double power = -MY_NAN;
  int i = _i;
  ck_assert_ldouble_nan(my_pow(x[i], power));
}
END_TEST

START_TEST(test30) {
  double x = -MY_NAN;
  double power[6] = {1, -1, -12221.1, 11.1334, MY_NAN, -MY_NAN};
  int i = _i;
  ck_assert_ldouble_nan(my_pow(x, power[i]));
}
END_TEST

START_TEST(test31) {
  double x = 1;
  double power[7] = {1, 0, -12221.1, 11.1334, -4, 899, -1};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(x, power[i]), my_pow(x, power[i]), 1e-6);
}
END_TEST

START_TEST(test32) {
  double x = 0.995214;
  double power[7] = {1, -1, -21.1, 11.1334, -45, 899, 2};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(x, power[i]), my_pow(x, power[i]), 1e-6);
}
END_TEST

START_TEST(test33) {
  double x[8] = {1.12, -34.45, INFINITY, -INFINITY, 12, -12, 13, -13};
  double power = INFINITY;
  int i = _i;
  ck_assert_ldouble_eq(pow(x[i], power), my_pow(x[i], power));
}
END_TEST

START_TEST(test34) {
  double power[8] = {1.12, -34.45, INFINITY, -INFINITY, 12, -12, 13, -13};
  double x = -INFINITY;
  int i = _i;
  ck_assert_ldouble_eq(pow(x, power[i]), my_pow(x, power[i]));
}
END_TEST

START_TEST(test35) {
  double x = -0.0;
  double power[8] = {
      0.0083928293832, -34.45, INFINITY, -INFINITY, 12, -12, -13, 13};
  ck_assert_ldouble_eq(pow(x, power[_i]), my_pow(x, power[_i]));
}
END_TEST

START_TEST(test36) {
  double x[6] = {0.0083925778682, -34.45, 12, -12, -0.0004, 0};
  double power[3] = {-1, 0, 1};
  for (int j = 0; j < 5; j++) {
    ck_assert_ldouble_eq_tol(pow(x[j], power[_i]), my_pow(x[j], power[_i]),
                             1e-6);
  }
}
END_TEST

START_TEST(test37) {
  double x[6] = {-1, -2, -3, -4, -5, -6};
  double power = 2;
  ck_assert_ldouble_eq_tol(pow(x[_i], power), my_pow(x[_i], power), 1e-6);
}
END_TEST

START_TEST(test38) {
  double x = 1e-2;
  double power[7] = {1, -1, -0.5, -1.5, -2, -2.5, -0.1};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(x, power[i]), my_pow(x, power[i]), 1e-6);
}
END_TEST

Suite *pow_suite(void) {
  Suite *test_suite = suite_create("pow_suite");
  TCase *test_case = tcase_create("pow_case");

  tcase_add_loop_test(test_case, test1, 0, 3);
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
  tcase_add_test(test_case, test23);
  tcase_add_test(test_case, test24);
  tcase_add_loop_test(test_case, test25, 0, 10);
  tcase_add_loop_test(test_case, test26, 0, 11);
  tcase_add_loop_test(test_case, test27, 0, 6);
  tcase_add_loop_test(test_case, test28, 0, 6);
  tcase_add_loop_test(test_case, test29, 0, 6);
  tcase_add_loop_test(test_case, test30, 0, 6);
  tcase_add_loop_test(test_case, test31, 0, 7);
  tcase_add_loop_test(test_case, test32, 0, 7);
  tcase_add_loop_test(test_case, test33, 0, 8);
  tcase_add_loop_test(test_case, test34, 0, 8);
  tcase_add_loop_test(test_case, test35, 0, 8);
  tcase_add_loop_test(test_case, test36, 0, 3);
  tcase_add_loop_test(test_case, test37, 0, 6);
  tcase_add_loop_test(test_case, test38, 0, 6);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}