#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

std::string dfs(const std::string& s, int& pos) {
  std::stringstream ss;
  int n = 1;
  int size = s.size();

  while (pos < size) {
    if ('0' <= s[pos] && s[pos] <= '9') {
      n = n * 10 + s[pos] - '0';
      pos++;
    } else if (s[pos] == '(') {
      pos++;
      std::string r0 = dfs(s, pos);
      for (int _ = 0; _ < n; _++) {
        ss << r0;
        if (ss.tellp() > size) {
          break;
        }
      }
      n = 1;
    } else {
      ss << std::string(n, s[pos]);
      n = 1;
      pos++;
    }
  }

  return ss.str();
}

int main() {
  for (;;) {
    std::string s;
    std::getline(std::cin, s);
    if (s == "0") {
      break;
    }
    int N;
    std::istringstream(s) >> s >> N;
    int pos = 0;
    std::string r = dfs(s, pos);
    std::cout << (r.size() > N ? r[N] : '0') << '\n';
  }

  return 0;
}