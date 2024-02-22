#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1000005;

int N;
char result[MAX_N];

int main() {
  for (;;) {
    char s[MAX_N];
    cin >> s >> N;
    if (strcmp(s, "0") == 0)
      break;
      
    int top = 0;
    int i = 0;
    long long n = -1;
    
    for (; s[i] != '\0';) {
      if ('0' <= s[i] && s[i] <= '9') {
        if (n < 0)
          n = s[i] - '0';
        else
          n = n * 10 + s[i] - '0';
        i++;
      } else if (s[i] == '(') {
        if (n < 0)
          n = 1;
        int cnt = 1;
        int j = i + 1;
        
        while (cnt > 0) {
          if (s[j] == '(')
            cnt++;
          else if (s[j] == ')')
            cnt--;
          j++;
        }
        
        for (int _ = 0; _ < n; _++) {
          int k = i + 1;
          while (k < j - 1) {
            result[top++] = s[k++];
            if (top > N)
              break;
          }
          if (top > N)
            break;
        }
        
        n = -1;
        i = j;
      } else {
        if (n < 0)
          n = 1;
        for (int _ = 0; _ < n; _++) {
          result[top++] = s[i];
          if (top > N)
            break;
        }
        n = -1;
        i++;
      }
      
      if (top > N)
        break;
    }
    
    result[top] = '\0';
    printf("%c\n", top > N ? result[N] : '0');
  }
}