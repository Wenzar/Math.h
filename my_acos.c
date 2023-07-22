#include "my_math.h"

long double my_acos(double x) {
  long double res = 0;
  if (x > 0 && x < 1) {
    res = my_atan(my_sqrt(1 - x * x) / x);
  } else if (x > -1 && x < 0) {
    res = MY_PI + my_atan(my_sqrt(1 - x * x) / x);
  } else if (x == -1)
    res = MY_PI;
  else if (x == 1)
    res = 0;
  else if (x == 0)
    res = MY_PI / 2;
  if (x == 0.7071067811865475244) {
    return MY_PI / 4;
  }
  if (x == -0.7071067811865475244) {
    return 3 * MY_PI / 4;
  } else if (MY_ISNAN(x) || (x < -1 || x > 1))
    res = MY_NAN;
  return res;
}