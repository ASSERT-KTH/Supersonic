#include <stdio.h>
#include <string.h>

int main() {
  int n;
  char t[256], i;
  
  while (scanf("%d", &n) == 1) {
    
    memset(t, 0, sizeof(t));  // zero out array
    
    while (n-- > 0) {
      scanf(" %c %c", &i, t);
      t[i] = *t;
    }
    
    scanf("%d", &n);  // read number of queries
    
    char queries[n + 1], results[n + 1];
    scanf("%s", queries);  // read all queries at once
    
    for (int j = 0; j < n; j++) {
      i = queries[j];
      results[j] = !t[i] * i + t[i];
    }
    
    results[n] = '\0';
    puts(results);  // print all results at once
  }
  
  return 0;
}