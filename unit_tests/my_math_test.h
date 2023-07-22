#ifndef MATH_TEST_H
#define MATH_TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../my_math.h"

Suite *fabs_suite(void);
Suite *floor_suite(void);
Suite *fmod_suite(void);
Suite *log_suite(void);
Suite *pow_suite(void);
Suite *sin_suite(void);
Suite *sqrt_suite(void);
Suite *tan_suite(void);
Suite *abs_suite(void);
Suite *exp_suite(void);
Suite *atan_suite(void);
Suite *ceil_suite(void);
Suite *asin_suite(void);
Suite *acos_suite(void);
Suite *cos_suite(void);

void run_testcase(Suite *testcase);

#endif  //  MATH_TEST_H