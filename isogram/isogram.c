#include "isogram.h"
#include <stdio.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
  int i = 0;
  bool result = true;

  if (phrase == 0) {
    return false;
  }

  if (phrase[i] == '\0') {
    return true;
  }

  for (; phrase[i] != '\0'; i++) {
    if (phrase[i] == '-' || phrase[i] == ' ') {
      continue;
    }
    for (int j = i + 1; phrase[j] != '\0' && result == true; j++) {

      bool exp = (phrase[i] != phrase[j]) && !((phrase[i] - 32 == phrase[j]) ||
                                               (phrase[i] + 32 == phrase[j]));

      // printf("phrase=[%c!=%c] phrase=[%d!=%d] compare=%d\n", phrase[i],
      //        phrase[j], phrase[i], phrase[j], exp);

      result &= exp;
    }
  }
  return result;
}
