#include "list_ops.h"
#include <stdio.h>

list_t *new_list(size_t length, list_element_t elements[]) {
  list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
  list->length = length;

  for (int i = 0; i < (int)length; i++) {
    list->elements[i] = elements[i];
  }

  return list;
}

void delete_list(list_t *list) {
  list->length = 0;
  free(list);
}

list_t *append_list(list_t *list1, list_t *list2) {
  int length = list1->length + list2->length;
  list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
  list->length = length;

  int i;
  for (i = 0; i < (int)list1->length; i++) {
    list->elements[i] = list1->elements[i];
  }

  for (int j = 0; j < (int)list2->length; j++) {
    list->elements[i + j] = list2->elements[j];
  }

  return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_t *filteredList = malloc(sizeof(list_t));
  filteredList->length = 0;

  int current = 0;
  for (int i = 0; i < (int)list->length; i++) {
    if (!filter(list->elements[i])) {
      continue;
    }

    filteredList = realloc(filteredList, sizeof(list_element_t));
    filteredList->elements[current++] = list->elements[i];
    filteredList->length++;
  }
  return filteredList;
}

size_t length_list(list_t *list) { return list->length; }

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_t *mapped = new_list(list->length, list->elements);
  for (int i = 0; i < (int)list->length; i++) {
    mapped->elements[i] = map(list->elements[i]);
  }
  return mapped;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t prev,
                                                  list_element_t curr)) {

  for (int i = 0; i < (int)list->length; i++) {
    initial = foldl(list->elements[i], initial);
  }
  return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  list_t *reversed = reverse_list(list);
  for (int i = 0; i < (int)reversed->length; i++) {
    initial = foldr(reversed->elements[i], initial);
  }
  return initial;
}

list_t *reverse_list(list_t *list) {
  list_t *reversed = new_list(list->length, list->elements);
  for (int i = list->length; i >= 0; i--) {
    reversed->elements[list->length - i] = list->elements[i - 1];
  }
  return reversed;
}
