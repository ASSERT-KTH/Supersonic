#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ope_line() {
  char line[256];
  fgets(line, sizeof(line), stdin);
  
  int len = strlen(line);
  char *train = (char*)malloc(len);
  int t = len / 2, s = len / 2;
  
  for (int i = 0; i < len; i += 2) {
    char a = line[i];
    char b = line[i + 1];
    char c = line[i + 2];
    
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>') {
      train[++t] = c;
    }
  }
  puts(&train[s]);
  free(train);
  
  if (feof(stdin))
    return false;
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