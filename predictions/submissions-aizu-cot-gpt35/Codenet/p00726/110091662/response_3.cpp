#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  for (;;) {
    string s;
    cin >> s;
    if (s == "0") break;

    int N;
    cin >> N;

    string r;
    stack<pair<int, int>> st; // stack to store state (n, i)

    int n = -1;
    for (int i = 0; i < s.size();) {
      if ('0' <= s[i] && s[i] <= '9') {
        if (n < 0)
          n = s[i] - '0';
        else
          n = n * 10 + s[i] - '0';
        i++;
      } else if (s[i] == '(') {
        if (n < 0)
          n = 1;
        st.push({n, i});
        n = -1;
        i++;
      } else if (s[i] == ')') {
        pair<int, int> state = st.top();
        st.pop();
        int start = state.second + 1;
        int end = i;
        string substr = s.substr(start, end - start);
        for (int _ = 0; _ < state.first; _++) {
          r += substr;
          if (r.size() > N) {
            printf("%c\n", r[N]);
            goto next_input;
          }
        }
        n = -1;
        i++;
      } else {
        if (n < 0)
          n = 1;
        r += string(n, s[i]);
        n = -1;
        i++;
        if (r.size() > N) {
          printf("%c\n", r[N]);
          goto next_input;
        }
      }
    }

    printf("%c\n", r.size() > N ? r[N] : '0');

  next_input:
    continue;
  }
}