#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index) {
  uint64_t amount = 1;

  if (index == 0 || index > 64) {
    return 0;
  }

  while (index - 1 > 0) {
    index--;
    amount *= 2;
  }

  return amount;
}

uint64_t total(void) {

  uint64_t total = 0;
  for (int index = 0; index <= 64; index++) {
    total += (uint64_t)square(index);
  }
  return total;
}
