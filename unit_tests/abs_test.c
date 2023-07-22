#include "my_math_test.h"

START_TEST(test1) {
  int x = -5;

  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test2) {
  int x = 5;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test3) {
  int x = -2147483647;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test4) {
  int x = -0xA23;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test5) {
  int x = 13;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test6) {
  int x = 0;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test7) {
  int x = -5;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test8) {
  int x = -45670;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

START_TEST(test9) {
  int x = 123456789;
  ck_assert_int_eq(my_abs(x), abs(x));
}
END_TEST

Suite *abs_suite(void) {
  Suite *test_suite = suite_create("abs_suite");
  TCase *test_case = tcase_create("abs_case");

  tcase_add_test(test_case, test1);
  tcase_add_test(test_case, test2);
  tcase_add_test(test_case, test3);
  tcase_add_test(test_case, test4);
  tcase_add_test(test_case, test5);
  tcase_add_test(test_case, test6);
  tcase_add_test(test_case, test7);
  tcase_add_test(test_case, test8);
  tcase_add_test(test_case, test9);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}