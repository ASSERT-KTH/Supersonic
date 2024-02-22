#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

int cket(const std::string& str, int i) {
  int n = 1;
  for (; i < str.size(); ++i) {
    if (str[i] == '(')
      n++;
    if (str[i] == ')')
      n--;
    if (n == 0)
      break;
  }
  return i;
}

char expand(const std::string& str) {
  std::stack<int> numStack;
  std::stack<int> sStack;
  std::stack<int> eStack;

  int i = 0;
  while (i < str.size()) {
    if (isdigit(str[i])) {
      int j = 1;
      while (isdigit(str[i + j]))
        j++;

      int num = std::stoi(str.substr(i, j));
      numStack.push(num);

      if (str[i + j] == '(') {
        sStack.push(i + j + 1);
        int k = cket(str, i + j + 1);
        eStack.push(k - (i + j + 1));
        i = k;
      } else {
        sStack.push(i + j);
        eStack.push(1);
        i = i + j;
      }
    } else {
      if (numStack.empty()) {
        return str[i];
      }
      int num = numStack.top();
      numStack.pop();
      int s = sStack.top();
      sStack.pop();
      int e = eStack.top();
      eStack.pop();
      for (int l = 0; l < num; ++l) {
        char a = expand(str.substr(s, e));
        if (a != '0')
          return a;
      }
    }
    i++;
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
    std::cout << expand(str) << std::endl;
  }
  return 0;
}