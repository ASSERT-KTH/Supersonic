#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

struct State {
  int num;
  std::string::iterator s, e;
};

char expand(std::string& str, int n) {
  std::stack<State> stack;
  std::string::iterator it = str.begin();
  while (it != str.end() || !stack.empty()) {
    if (it != str.end() && isdigit(*it)) {
      int num = 0;
      while (isdigit(*it))
        num = num * 10 + (*it++ - '0');
      std::string::iterator s, e;
      if (*it == '(') {
        std::stack<char> brackets;
        brackets.push(*it++);
        s = it;
        while (!brackets.empty()) {
          if (*it == '(')
            brackets.push(*it);
          if (*it == ')')
            brackets.pop();
          it++;
        }
        e = it - 1;
      } else {
        s = it++;
        e = it;
      }
      stack.push({num, s, e});
    } else {
      if (!stack.empty()) {
        State& top = stack.top();
        if (n == 0)
          return *top.s;
        n--;
        if (++top.s == top.e)
          stack.pop();
      } else {
        if (n == 0)
          return *it;
        n--;
        it++;
      }
    }
  }
  return '0';
}

int main(void) {
  while (true) {
    std::string str;
    int n;
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str, n) << std::endl;
  }
  return 0;
}