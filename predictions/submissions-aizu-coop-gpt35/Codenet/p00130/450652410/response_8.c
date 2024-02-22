#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char* train = NULL;
  int t = 0, s = 0;
  int train_size = 0;
  
  int c = getchar();
  t++;
  train_size++;
  train = (char*) realloc(train, train_size * sizeof(char));
  train[t] = c;
  
  int a;
  do {
    int b = getchar();
    c = getchar();
    if (a == '<' && b == '-') {
      t--;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>') {
      t++;
      train_size++;
      train = (char*) realloc(train, train_size * sizeof(char));
      train[t] = c;
    }
    a = c;
  } while (a != '\n' && a != EOF);
  
  printf("%s\n", &train[s]);
  
  if (a == EOF) {
    free(train);
    return false;
  }
  
  free(train);
  return true;
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  
  for (int i = 0; i < n; i += 4) {
    if (!ope_line()) break;
    if (!ope_line()) break;
    if (!ope_line()) break;
    if (!ope_line()) break;
  }
  
  return 0;
}