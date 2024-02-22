#include <iostream>
#include <string>

std::string dfs(const std::string& s, int N) {
  std::string r;
  int i = 0;
  long long n = -1;
  for (; i < s.size();) {
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
      std::string r0 = dfs(s.substr(i + 1, j - 1 - i - 1), N);
      for (int _ = 0; _ < n; _++) {
        r += r0;
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r.append(n, s[i]);
      n = -1;
      i++;
    }
  }
  return r;
}

int main() {
  for (;;) {
    std::string s;
    int N;
    std::cin >> s >> N;
    if (s == "0")
      break;
    std::string r;
    r.reserve(N + 1);
    r = dfs(s, N);
    std::cout << (r.size() > N ? r[N] : '0') << '\n';
  }
  return 0;
}