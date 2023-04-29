#include "square_root.h"
#include <math.h>
#include <stdio.h>

int square_root(int base) {
  if (base <= 1) {
    return 1;
  }

  double prev = (double)base / 2;

  double curr = 0;

  for (int i = 0; i < 10; i++) {
    curr = (prev + base / prev) / 2;

    if (trunc(1. * curr) == trunc(1. * prev)) {
      break;
    }
    prev = curr;
  }

  return trunc(1. * curr);
}
