#include "my_math_test.h"

START_TEST(test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = INFINITY;
  ck_assert_ldouble_eq(my_floor(x), floor(x));
}
END_TEST

START_TEST(test5) {
  double x = -INFINITY;
  ck_assert_ldouble_eq(my_floor(x), floor(x));
}
END_TEST

START_TEST(test6) {
  double x = NAN;
  ck_assert_ldouble_nan(my_floor(x));
}
END_TEST

START_TEST(test7) {
  double x = -487.756145;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = 4731454425456789076.5;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = -4.7323234567890765;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = -4731454425456789076.5;
  ck_assert_ldouble_eq_tol(my_floor(x), floor(x), 1e-6);
}
END_TEST

START_TEST(test13) {
  ck_assert_ldouble_eq(floor(INFINITY), my_floor(INFINITY));
}
END_TEST
START_TEST(test12) {
  ck_assert_ldouble_eq(floor(-INFINITY), my_floor(-INFINITY));
}
END_TEST

START_TEST(test14) { ck_assert_ldouble_nan(my_floor(MY_NAN)); }
END_TEST

START_TEST(test15) {
  ck_assert_ldouble_eq(floor(0.1234569033337912345),
                       my_floor(0.1234569033337912345));
}
END_TEST

Suite *floor_suite(void) {
  Suite *test_suite = suite_create("floor_suite");
  TCase *test_case = tcase_create("floor_case");

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