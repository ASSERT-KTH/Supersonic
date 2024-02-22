#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const char NUL = '\0';

typedef struct {
  char buffer[52];
  int start;
  int end;
} CircularBuffer;

void circular_buffer_init(CircularBuffer* cb) {
  cb->start = 0;
  cb->end = 0;
}

void circular_buffer_insert(CircularBuffer* cb, char c) {
  cb->buffer[cb->end] = c;
  cb->end = (cb->end + 1) % 52;
}

void circular_buffer_remove(CircularBuffer* cb) {
  cb->start = (cb->start + 1) % 52;
}

bool ope_line() {
  CircularBuffer train;
  circular_buffer_init(&train);

  char buffer[1024];
  fgets(buffer, sizeof(buffer), stdin);

  int i = 0;
  while (buffer[i] != NUL && buffer[i] != '\n') {
    int a = buffer[i++];
    int b = buffer[i++];
    int c = buffer[i++];

    if (a == '<' && b == '-') {
      circular_buffer_insert(&train, c);
    } else if (a == '-' && b == '>') {
      circular_buffer_remove(&train);
      circular_buffer_insert(&train, c);
    }
  }

  for (int i = train.start; i != train.end; i = (i + 1) % 52) {
    putchar(train.buffer[i]);
  }
  putchar('\n');

  if (buffer[i] == '\n') {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}