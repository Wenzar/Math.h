#include "my_math.h"

long double my_exp(double x) {
  long double temp = 1;
  long double result = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  for (long double i = 1; my_fabs(temp) > MY_EPS; i++) {
    temp *= x / i;
    result += temp;
    if (result > 1e100) {
      result = MY_INF;
      break;
    }
  }
  if (flag == 1) {
    if (result > 1e100) {
      result = 0;
    } else {
      result = 1.0 / result;
    }
  }
  if (result > 1e100) {
    return MY_INF;
  }
  return result;
}