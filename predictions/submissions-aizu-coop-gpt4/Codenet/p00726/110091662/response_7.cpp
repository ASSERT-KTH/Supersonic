#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct State {
  int i;
  long long n;
  vector<char> r;
};

string dfs(const string& s, int start, int end) {
  stack<State> st;
  st.push({start, -1, {}});
  while (!st.empty()) {
    State& state = st.top();
    if (state.i < end) {
      if ('0' <= s[state.i] && s[state.i] <= '9') {
        if (state.n < 0)
          state.n = s[state.i] - '0';
        else
          state.n = state.n * 10 + s[state.i] - '0';
        state.i++;
      } else if (s[state.i] == '(') {
        if (state.n < 0)
          state.n = 1;
        int cnt = 1, j = state.i + 1;
        for (; cnt; j++) {
          if (s[j] == '(')
            cnt++;
          else if (s[j] == ')')
            cnt--;
        }
        st.push({state.i + 1, -1, {}});
        state.n = -1;
        state.i = j;
      } else {
        if (state.n < 0)
          state.n = 1;
        for (int _ = 0; _ < state.n; _++)
          state.r.push_back(s[state.i]);
        state.n = -1;
        state.i++;
      }
    } else {
      if (st.size() > 1) {
        State temp = st.top();
        st.pop();
        for (int _ = 0; _ < st.top().n; _++) {
          for (char c : temp.r) {
            st.top().r.push_back(c);
            if (st.top().r.size() > N)
              break;
          }
        }
      } else {
        break;
      }
    }
  }
  return string(st.top().r.begin(), st.top().r.end());
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    string r = dfs(s, 0, s.size());
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}