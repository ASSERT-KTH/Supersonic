#include <iostream>
#include <string>

bool ope_line() {
  std::string train(52, '\0');
  int t = 25, s = 25;
  char c, a, b;
  std::cin >> c;
  train[t] = c;
  std::cin >> a;
  while (a != '\n' && !std::cin.eof()) {
    std::cin >> b >> c;
    if (a == '<' && b == '-') {
      train[--t] = c;
      s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
    std::cin >> a;
  }
  std::cout << train.substr(s, t-s+1) << "\n";
  return !std::cin.eof();
}

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}