#include <cstdio>

int N;
char s[1000001];
char r[1000001];
int rIndex;

void evaluateNestedParentheses() {
  int i = 0;
  long long n = -1;
  while (s[i] != '\0') {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt;) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      evaluateNestedParentheses();
      for (int _ = 0; _ < n; _++) {
        for (int k = 0; k < rIndex; k++) r[rIndex++] = r[k];
        if (rIndex > N)
          return;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      for (int _ = 0; _ < n; _++) r[rIndex++] = s[i];
      n = -1;
      i++;
    }
  }
}

int main() {
  for (;;) {
    scanf("%s %d", s, &N);
    if (s[0] == '0')
      break;
    rIndex = 0;
    evaluateNestedParentheses();
    printf("%c\n", (rIndex > N ? r[N] : '0'));
  }
}