#include "hamming.h"
#include <stdio.h>

int compute(const char *lhs, const char *rhs) {
  int distance = 0;
  int index = 0;

  int lhsLenght = 0;
  for (lhsLenght = 0; *(lhs + lhsLenght) != '\0'; ++lhsLenght)
    ;

  int rhsLenght = 0;
  for (rhsLenght = 0; *(rhs + rhsLenght) != '\0'; ++rhsLenght)
    ;

  if (lhsLenght != rhsLenght) {
    return -1;
  }

  if (*lhs == '\0') {
    return 0;
  }

  while (*(lhs + index) != '\0') {
    distance += *(lhs + index) != *(rhs + index);
    index++;
  }

  return distance;
}
