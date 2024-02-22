#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

char x[1000005];
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0;

int main() {
  scanf("%s", x);
  int leng = strlen(x);
  stack<int> st;
  
  for (int i = 0; i < leng; i++) {
    if (x[i] == 'J') {
      b++;
    } else if (x[i] == 'O') {
      c++;
    } else if (x[i] == 'I') {
      d++;
    }
    if (b >= c && c <= d) {
      st.push(c);
    }
    if (x[i] != x[i + 1]) {
      b = 0;
      c = 0;
      d = 0;
    }
  }
  
  while (!st.empty()) {
    maxi = max(maxi, st.top());
    st.pop();
  }
  
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}