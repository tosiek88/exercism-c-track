#include "rational_numbers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

rational_t add(rational_t r1, rational_t r2) {
  // (a₁ * b₂ + a₂ * b₁) / (b₁ * b₂)
  rational_t r;
  r.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
  r.denominator = r1.denominator * r2.denominator;
  if (r.numerator == 0) {
    r.denominator = 1;
  }
  return r;
}

rational_t subtract(rational_t r1, rational_t r2) {

  rational_t r;
  // (a₁ * b₂ - a₂ * b₁) / (b₁ * b₂)
  r.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
  r.denominator = r1.denominator * r2.denominator;
  if (r.numerator == 0) {
    r.denominator = 1;
  }
  return r;
}

rational_t multiply(rational_t r1, rational_t r2) {

  rational_t r;
  // (a₁ * b₂ - a₂ * b₁) / (b₁ * b₂)
  r.numerator = r1.numerator * r2.numerator;
  r.denominator = r1.denominator * r2.denominator;

  if (r.numerator == 0) {
    r.denominator = 1;
  }

  return reduce(r);
}

rational_t divide(rational_t r1, rational_t r2) {
  return multiply(r1, (rational_t){r2.denominator, r2.numerator});
}

rational_t absolute(rational_t r) {
  return reduce((rational_t){abs(r.numerator), abs(r.denominator)});
}

rational_t exp_rational(rational_t r, int16_t n) {
  rational_t prev = r;
  int mantisa = abs(n);

  if (n == 0) {
    return (rational_t){1, 1};
  }

  for (; mantisa > 1; --mantisa) {
    prev = multiply(prev, r);
  }

  if (n < 0) {
    return divide((rational_t){1, 1}, prev);
  }

  return prev;
}

float exp_real(uint16_t x, rational_t r) {
  return powf(x, (float)((float)(r.numerator) / (float)(r.denominator)));
}

rational_t reduce(rational_t r) {
  rational_t tmp = (rational_t){abs(r.numerator), abs(r.denominator)};
  int sign = (r.denominator < 0) ? -1 : 1;

  while (tmp.denominator != 0) {
    int t = tmp.denominator;
    tmp.denominator = tmp.numerator % tmp.denominator;
    tmp.numerator = t;
  }

  r.numerator /= tmp.numerator * sign;
  r.denominator /= tmp.numerator * sign;

  return r;
}
