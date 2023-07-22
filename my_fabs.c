#include "my_math.h"

long double my_fabs(double x) {
  long double result = 0;
  if (x == 0.0) {
    result = 0.0;
  } else {
    result = x > 0 ? x : (x *= -1);
  }
  return result;
}