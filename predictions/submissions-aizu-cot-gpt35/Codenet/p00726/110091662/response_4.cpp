#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    if (line == "0")
      break;

    std::istringstream iss(line);
    std::string s;
    int N;
    iss >> s >> N;

    std::string result;
    std::stack<int> counts;
    std::stack<std::string> substrings;

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
        counts.push(n);
        substrings.push(result);
        n = -1;
        i++;
      } else if (s[i] == ')') {
        int cnt = counts.top();
        counts.pop();
        std::string r0 = result.substr(substrings.top().size());
        substrings.pop();
        for (int _ = 0; _ < cnt; _++) {
          result += r0;
          if (result.size() > N)
            break;
        }
        n = -1;
        i++;
      } else {
        if (n < 0)
          n = 1;
        result += std::string(n, s[i]);
        n = -1;
        i++;
      }
    }

    std::cout << (result.size() > N ? result[N] : '0') << "\n";
  }

  return 0;
}