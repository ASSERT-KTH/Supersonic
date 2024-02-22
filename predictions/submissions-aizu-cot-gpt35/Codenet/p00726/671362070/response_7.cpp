#include <iostream>
#include <string>
#include <stack>

int cket(const std::string& str, int i) {
  std::stack<char> stk;
  stk.push(str[i]);
  
  while (!stk.empty()) {
    ++i;
    
    if (str[i] == '(')
      stk.push('(');
    else if (str[i] == ')')
      stk.pop();
  }
  
  return i;
}

char expand(const std::string& str) {
  int n = 0;
  
  for (int i = 0; i < str.size(); ++i) {
    if (std::isdigit(str[i])) {
      int j = i + 1;
      
      while (std::isdigit(str[j]))
        ++j;
      
      int num = std::stoi(str.substr(i, j - i));
      
      int s, e;
      if (str[j] == '(') {
        int k = cket(str, j + 1);
        s = j + 1;
        e = k - (j + 1);
        i = k;
      } else {
        s = j;
        e = 1;
        i = j;
      }
      
      for (int l = 0; l < num; ++l) {
        char a = expand(str.substr(s, e));
        if (a != '0')
          return a;
      }
    } else {
      if (n == 0) {
        return str[i];
      }
      --n;
    }
  }
  
  return '0';
}

int main() {
  std::string str;
  int n;
  
  do {
    std::cin >> str >> n;
    if (str == "0" && n == 0)
      break;
    std::cout << expand(str) << std::endl;
  } while (true);
  
  return 0;
}