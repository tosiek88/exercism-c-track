#include "circular_buffer.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

circular_buffer_t *new_circular_buffer(size_t capacity) {
  circular_buffer_t *circularBuffer = malloc(sizeof(circular_buffer_t));
  circularBuffer->capacity = capacity;
  circularBuffer->ptr = malloc(sizeof(int) * capacity);
  circularBuffer->headPos = 0;
  circularBuffer->tailPos = 0;
  circularBuffer->space = capacity;

  return circularBuffer;
}

bool isEmpty(circular_buffer_t *buffer) {
  return buffer->capacity == buffer->space;
}

bool isFull(circular_buffer_t *buffer) { return buffer->space == 0; }

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value) {
  if (buffer == NULL || buffer->ptr == NULL || isEmpty(buffer)) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  *read_value = buffer->ptr[buffer->tailPos];

  buffer->ptr[buffer->tailPos] = 0;
  buffer->tailPos = (buffer->tailPos + 1) % (buffer->capacity);
  buffer->space++;

  return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer == NULL || buffer->ptr == NULL) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  if (isFull(buffer)) {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }

  buffer->ptr[buffer->headPos] = value;
  buffer->headPos = (buffer->headPos + 1) % (buffer->capacity);
  buffer->space--;

  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer == NULL || buffer->ptr == NULL) {
    return EXIT_FAILURE;
  }

  if (!isFull(buffer)) {
    return write(buffer, value);
  }

  buffer->ptr[buffer->tailPos] = value;
  buffer->tailPos = (buffer->tailPos + 1) % (buffer->capacity);

  return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
  buffer->headPos = 0;
  buffer->tailPos = 0;
  buffer->space = buffer->capacity;
  free(buffer->ptr);
}

void delete_buffer(circular_buffer_t *buffer) { free(buffer); }
