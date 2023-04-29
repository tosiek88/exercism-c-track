#include "binary_search.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length) {
  int offset = (int)round((int)(length / 2));

  if ((length == 1 && (*(arr + offset)) != value) || length == 0) {
    return NULL;
  }

  if ((*(arr + offset)) == value) {
    return &arr[offset];
  }

  if ((*(arr + offset)) > value) {
    return binary_search(value, arr, offset);
  }

  if ((*(arr + offset)) < value) {
    return binary_search(value, arr + offset, length - offset);
  }

  return NULL;
}
