#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char *train = malloc(52 * sizeof(char));
  if (!train) {
    fprintf(stderr, "Failed to allocate memory for train.\n");
    exit(EXIT_FAILURE);
  }
  int t = 25, s = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = '\0';

  char input[5]; // buffer to hold input command
  while (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
    int direction = (input[0] == '<' && input[1] == '-') ? --t : ++t;
    train[direction] = input[2];
    if (direction < s)
      s = direction;
  }

  printf("%s\n", &train[s]);
  
  free(train);
  
  if (feof(stdin)) return false;
  return true;
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}