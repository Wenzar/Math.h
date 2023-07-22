#include "my_math.h"

long double my_fmod(double x, double y) {
  long double result = x;

  if (MY_ISNAN(x) || MY_ISNAN(y) || MY_ISINF(x) || y == 0) {
    result = MY_NAN;
  } else if (x == 0.0) {
    result = 0.0;
  } else if (MY_ISINF(y)) {
    result = x;
  } else if (y > x) {
    result = x;
  } else {
    if (x < 0 || y < 0) {
      result = (long long int)-my_fabs(x / y);
    } else {
      result = (long long int)my_fabs(x / y);
    }
    result = x - result * y;
  }
  return result;
}