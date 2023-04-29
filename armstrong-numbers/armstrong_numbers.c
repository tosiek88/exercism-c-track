#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>

bool is_armstrong_number(int candidate) {
  int wages[7] = {0};
  int index = 0;
  int tempCandidate = candidate;

  while (tempCandidate != 0) {
    wages[index] = tempCandidate % 10;
    tempCandidate /= 10;

    if (tempCandidate == 0) {
      break;
    }

    index++;
  };

  const int total = index;
  int accumulate = 0;
  for (; index >= 0; index--) {
    int result = 1;

    for (int exp = total; exp >= 0; exp--) {
      result *= wages[index];
    }

    accumulate += result;
  }

  return accumulate == candidate;
}
