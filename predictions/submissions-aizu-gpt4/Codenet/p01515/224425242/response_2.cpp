#include <iostream>
#include <bitset>

constexpr int kMaxVariables = 11;

bool solve(const std::string &s) {
  for (int mask = 0; mask < (1 << kMaxVariables); ++mask) {
    std::bitset<kMaxVariables> bits(mask);
    std::string::size_type pos = 0;
    if (!expression(s, pos, bits)) {
      return false;
    }
  }
  return true;
}

bool expression(const std::string &s, std::string::size_type &pos, const std::bitset<kMaxVariables> &bits) {
  bool left = term(s, pos, bits);
  while (pos < s.length() && s[pos] == '-') {
    ++pos;
    bool right = term(s, pos, bits);
    left = left == right;
  }
  return left;
}

bool term(const std::string &s, std::string::size_type &pos, const std::bitset<kMaxVariables> &bits) {
  bool left = factor(s, pos, bits);
  while (pos < s.length() && s[pos] != '-' && s[pos] != ')') {
    char op = s[pos++];
    bool right = factor(s, pos, bits);
    switch (op) {
      case '*':
        left = left && right;
        break;
      case '+':
        left = left || right;
        break;
      default:
        left = !left || right;
        break;
    }
  }
  return left;
}

bool factor(const std::string &s, std::string::size_type &pos, const std::bitset<kMaxVariables> &bits) {
  char ch = s[pos++];
  if (ch == '(') {
    bool value = expression(s, pos, bits);
    ++pos;  // skip ')'
    return value;
  } else if (ch == '-') {
    return !factor(s, pos, bits);
  } else if (ch == 'T') {
    return true;
  } else if (ch == 'F') {
    return false;
  } else {
    return bits[ch - 'a'];
  }
}

int main() {
  std::string s;
  while (std::cin >> s && s != "#") {
    std::cout << (solve(s) ? "YES\n" : "NO\n");
  }
  return 0;
}