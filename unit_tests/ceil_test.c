#include "my_math_test.h"

START_TEST(test1) {
  double x = .0;
  ck_assert_ldouble_eq_tol(my_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(my_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(test3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(my_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(test4) {
  double x = INFINITY;
  ck_assert_ldouble_eq(my_ceil(x), ceil(x));
}
END_TEST

START_TEST(test5) {
  double x = -INFINITY;
  ck_assert_ldouble_eq(my_ceil(x), ceil(x));
}
END_TEST

START_TEST(test6) {
  double x = MY_NAN;
  ck_assert_ldouble_nan(my_ceil(x));
}
END_TEST

START_TEST(test7) {
  double x = 4.447;
  ck_assert_ldouble_eq_tol(my_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(test8) {
  double x = 4.473232789076;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 6);
}
END_TEST

START_TEST(test9) {
  double x = 473232789076.5;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 6);
}
END_TEST

START_TEST(test10) {
  double x = -4.473232789076;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 6);
}
END_TEST

START_TEST(test11) {
  double x = -473232789076.5;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 6);
}
END_TEST

START_TEST(test12) {
  ck_assert_ldouble_infinite(my_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(test13) {
  ck_assert_ldouble_nan(my_ceil(MY_NAN));
  ck_assert_ldouble_nan(ceil(MY_NAN));
}
END_TEST

START_TEST(test14) { ck_assert_ldouble_eq(my_ceil(0), ceil(0)); }
END_TEST

START_TEST(test15) {
  double x = 87435471375471154.3414313413;
  ck_assert_ldouble_eq(my_ceil(x), ceil(x));
}

START_TEST(test16) {
  double x = -87435471375471154.3414313413;
  ck_assert_ldouble_eq(my_ceil(x), ceil(x));
}

START_TEST(test17) { ck_assert_ldouble_eq(ceil(0.76), my_ceil(0.76)); }
END_TEST

START_TEST(test18) { ck_assert_ldouble_eq(ceil(-12234), my_ceil(-12234)); }
END_TEST

START_TEST(test19) { ck_assert_ldouble_eq(ceil(11234), my_ceil(11234)); }
END_TEST

START_TEST(test20) { ck_assert_ldouble_eq(ceil(1), my_ceil(1)); }
END_TEST

START_TEST(test21) { ck_assert_ldouble_eq(ceil(1.722), my_ceil(1.722)); }
END_TEST

START_TEST(test22) { ck_assert_int_eq(ceil(-1.557), my_ceil(-1.557)); }
END_TEST

START_TEST(test23) { ck_assert_int_eq(floor(-0.733), my_floor(-0.733)); }
END_TEST

START_TEST(test24) { ck_assert_ldouble_eq(ceil(144.7), my_ceil(144.7)); }
END_TEST
START_TEST(test26) { ck_assert_ldouble_eq(ceil(0.745), my_ceil(0.745)); }
END_TEST
START_TEST(test27) { ck_assert_ldouble_eq(ceil(INFINITY), my_ceil(INFINITY)); }
END_TEST
START_TEST(test25) {
  ck_assert_ldouble_eq(ceil(-INFINITY), my_ceil(-INFINITY));
}
END_TEST

START_TEST(test28) {
  double x = 0.3;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(x * i), my_ceil(x * i), 1e-6);
}
END_TEST

START_TEST(test29) {
  double x = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(-x * i), my_ceil(-x * i), 1e-6);
}
END_TEST

START_TEST(test30) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(ceil(x), my_ceil(x));
}
END_TEST

START_TEST(test31) {
  double x = 9999999999999999.999999;
  ck_assert_ldouble_eq(ceil(x), my_ceil(x));
}
END_TEST

Suite *ceil_suite(void) {
  Suite *test_suite = suite_create("ceil_suite");
  TCase *test_case = tcase_create("ceil_case");

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
  tcase_add_test(test_case, test23);
  tcase_add_test(test_case, test24);
  tcase_add_test(test_case, test25);
  tcase_add_test(test_case, test26);
  tcase_add_test(test_case, test27);
  tcase_add_loop_test(test_case, test28, 0, 100);
  tcase_add_loop_test(test_case, test29, 0, 100);
  tcase_add_test(test_case, test30);
  tcase_add_test(test_case, test31);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}