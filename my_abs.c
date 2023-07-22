#include "my_math.h"

int my_abs(int x) {
  long long int result = (long long int)x;
  if (result < 0) result = -result;
  return result;
}