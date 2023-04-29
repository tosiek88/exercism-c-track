#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

typedef int buffer_value_t;
typedef struct {
  int capacity;
  int *ptr;

  int headPos;
  int tailPos;
  uint16_t space;
  int overridePos;

} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value);

bool isEmpty(circular_buffer_t *buffer);
bool isFull(circular_buffer_t *buffer);

void delete_buffer(circular_buffer_t *buffer);
void clear_buffer(circular_buffer_t *buffer);

#endif
