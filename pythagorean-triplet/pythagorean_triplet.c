#include "pythagorean_triplet.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum) {
  triplets_t *triplets = malloc(sizeof(triplets_t) + sizeof(triplet_t) * 100);
  triplets->count = 0;

  int a, b, c = 0;
  int b_rest = 0;

  for (a = 1; a < sum; a++) {
    b = (sum * sum - 2 * sum * a) / (2 * sum - 2 * a);
    b_rest = (sum * sum - 2 * sum * a) % (2 * sum - 2 * a);
    c = (sum - b - a);

    if (a * a + b * b == c * c && c > b && b > a && b > 0 && c > 0 &&
        b_rest == 0 && (a + b + c) == sum) {
      triplet_t triplet = {a, b, c};
      triplets->triplets[triplets->count] = triplet;
      triplets->count++;
    }
  }

  return triplets;
}

void free_triplets(triplets_t *triplets) { free(triplets); }
