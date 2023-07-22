#include "my_math_test.h"

START_TEST(test1) {
  double x = 1.0000;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test2) {
  double x = -1.00110005;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test3) {
  double x = 0.0;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test4) {
  double x = -0.0;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test5) {
  double x = INFINITY;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test6) {
  double x = -INFINITY;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test7) { ck_assert_ldouble_nan(my_fabs(NAN)); }
END_TEST

START_TEST(test8) {
  double x = 122000.042;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test9) {
  double x = -122000.042;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test10) {
  double x = 93387633.465;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

START_TEST(test11) {
  double x = -9223123341242143.4633335;
  ck_assert_ldouble_eq(my_fabs(x), fabs(x));
}
END_TEST

Suite *fabs_suite(void) {
  Suite *test_suite = suite_create("fabs_suite");
  TCase *test_case = tcase_create("fabs_case");

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

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}