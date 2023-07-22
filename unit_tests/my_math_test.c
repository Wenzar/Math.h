#include "my_math_test.h"

int main(void) {
  Suite *list_testcases[] = {
      fabs_suite(), floor_suite(), fmod_suite(), log_suite(),
      pow_suite(),  sin_suite(),   sqrt_suite(), tan_suite(),
      abs_suite(),  exp_suite(),   atan_suite(), ceil_suite(),
      asin_suite(), acos_suite(),  cos_suite(),  NULL};
  for (Suite **testcase = list_testcases; *testcase != NULL; testcase++) {
    run_testcase(*testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  static int testcase_count = 1;

  if (testcase_count > 0) {
    putchar('\n');
  }
  printf("%s%d%s", "TEST №", testcase_count, "\n");
  testcase_count++;
  SRunner *suiteRun = srunner_create(testcase);

  srunner_set_fork_status(suiteRun, CK_NOFORK);
  srunner_run_all(suiteRun, CK_NORMAL);

  srunner_free(suiteRun);
}
