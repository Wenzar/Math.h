#include "my_math.h"

long double my_floor(double x) {
  long double result = (long long int)x;
  if (x == 0 || MY_ISINF(x) || MY_ISNAN(x)) {
    result = x;
  } else {
    if (x < 0 && my_fabs(x - result) > 0.0) {
      result -= 1;
    }
  }
  return result;
}