#include "my_math.h"

long double my_atan(double x) {
  long double res = 0;
  if (x == 0.0)
    res = 0.0;
  else if (x == 1.0 || x == -1.0) {
    if (x == 1.0)
      res = MY_PI / 4.0;
    else
      res = MY_PI / 4.0 * (-1);
  } else if (x == MY_INF || x > 1e100) {
    res = MY_PI / 2;
  } else if (x == -MY_INF) {
    res = -MY_PI / 2;
  } else if (-1.0 < x && x < 1.0) {
    for (int i = 0; i < 5000; i++) {
      res += my_pow(-1, i) * my_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 7000; i++) {
      res += my_pow(-1, i) * my_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    res = MY_PI * my_sqrt(x * x) / (2 * x) - res;
  }

  return res;
}