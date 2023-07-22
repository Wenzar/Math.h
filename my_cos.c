#include "my_math.h"

long double my_cos(double x) {
  long double res = 0;
  res = my_sin(x + MY_PI / 2.0);
  return res;
}