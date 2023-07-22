#ifndef MATH_H
#define MATH_H

#define MY_INF __builtin_inf()
#define MY_NAN __builtin_nan("")
#define MY_ISINF __builtin_isinf
#define MY_ISNAN __builtin_isnan
#define MY_EXP 2.7182818284590452353
#define MY_PI 3.141592653589793
#define MY_EPS 1e-100
#define MAX 1e100
#define MYPOS_INF(x) (x == MY_INF)
#define MYNEG_INF(x) (x == -MY_INF)

int my_abs(int x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double power);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_atan(double x);
long double my_exp(double x);
long double my_asin(double x);
long double my_acos(double x);
long double my_cos(double x);
long double my_ceil(double x);

#endif
