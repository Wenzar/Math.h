#include "my_math.h"

long double my_ceil(double x) {
  long double res = (long long int)x;
  if (MY_ISNAN(x)) {
    res = MY_NAN;
  } else if (MYPOS_INF(x)) {
    res = MY_INF;
  } else if (MYNEG_INF(x)) {
    res = -MY_INF;
  } else if (x > 0 && x != res) {
    res += 1;
  }
  return res;
}