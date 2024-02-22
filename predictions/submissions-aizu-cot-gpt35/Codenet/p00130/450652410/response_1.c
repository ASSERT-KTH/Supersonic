#include <stdbool.h>
#include <stdio.h>

bool ope_line() {
  char train[52];
  int t = 25, s = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = '\0';
  
  char line[100];
  fgets(line, sizeof(line), stdin);
  
  int i = 0;
  while (line[i] != '\n' && line[i] != '\0') {
    char a = line[i];
    char b = line[i + 1];
    char c = line[i + 2];
    
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
      
    i += 3;
  }
  
  puts(&train[s]);
  
  if (line[i] == '\0')
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