#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ope_line() {
  char* train = NULL;
  int t = 25, s = 25;
  
  size_t train_size = 52;
  train = (char*)malloc(train_size * sizeof(char));
  
  char line[100];
  fgets(line, sizeof(line), stdin);
  
  size_t line_length = strlen(line);
  
  for (size_t i = 0; i < line_length; ++i) {
    char a = line[i];
    char b = line[i+1];
    char c = line[i+2];
    
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
  }
  
  printf("%s\n", &train[s]);
  
  free(train);
  
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