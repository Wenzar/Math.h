#include "my_math_test.h"

START_TEST(test1) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test2) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test4) {
  double x = 1;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test6) {
  double x = -1;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test7) {
  double x = 400000.23;
  /* 598987986; */
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test8) {
  double x = -400000.23;
  /* 5938409234; */
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test9) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test10) {
  double x = 1 + 1e-6;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test11) {
  double x = -1 - 1e-6;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test12) { ck_assert_ldouble_nan(my_tan(INFINITY)); }
END_TEST

START_TEST(test13) { ck_assert_ldouble_nan(my_tan(MY_NAN)); }
END_TEST

START_TEST(test14) { ck_assert_ldouble_nan(my_tan(-INFINITY)); }
END_TEST

START_TEST(test15) {
  double x = MY_PI;
  ck_assert_ldouble_eq_tol(tan(x), my_tan(x), 1e-6);
}
END_TEST

START_TEST(test16) {
  int i = _i;
  if (i != 2 && i != -2) {
    if (i != 0) {
      ck_assert_ldouble_eq_tol(tan(MY_PI / i), my_tan(MY_PI / i), 1e-6);
    } else {
      ck_assert_ldouble_nan(my_tan(MY_PI / i));
    }
  }
}
END_TEST

START_TEST(test17) {
  int i = _i;
  ck_assert_ldouble_eq_tol(tan(MY_PI * i), my_tan(MY_PI * i), 1e-6);
}
END_TEST

Suite *tan_suite(void) {
  Suite *test_suite = suite_create("tan_suite");
  TCase *test_case = tcase_create("tan_case");

  tcase_add_test(test_case, test1);
  tcase_add_test(test_case, test2);
  tcase_add_test(test_case, test3);
  tcase_add_test(test_case, test4);
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
  tcase_add_loop_test(test_case, test16, -16, 16);
  tcase_add_loop_test(test_case, test17, -16, 16);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}