#include <cstdio>
#include <iostream>
#include <string>

std::string dfs(const std::string& s, int& i, int N) {
  std::string r;
  long long n = 1;

  for (; i < s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = n * 10 + (s[i] - '0');
    } else if (s[i] == '(') {
      i++;
      std::string r0 = dfs(s, i, N);
      for (int _ = 0; _ < n; _++) {
        if (r.size() > N) {
          return r;
        }
        r += r0;
      }
      n = 1;
    } else if (s[i] == ')') {
      return r;
    } else {
      if (r.size() > N) {
        return r;
      }
      r += s[i];
    }
  }

  return r;
}

int main() {
  for (;;) {
    std::string s;
    int N;
    std::cin >> s >> N;

    if (s == "0") {
      break;
    }

    int i = 0;
    std::string r = dfs(s, i, N);
    std::printf("%c\n", r.size() > N ? r[N] : '0');
  }

  return 0;
}