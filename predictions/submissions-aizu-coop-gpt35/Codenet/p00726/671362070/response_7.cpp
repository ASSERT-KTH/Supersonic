#include <stack>

int findClosingParenthesis(const std::string& str, int i) {
  std::stack<int> parenthesesStack;
  
  for (; i < str.size(); ++i) {
    if (str[i] == '(') {
      parenthesesStack.push(i);
    } else if (str[i] == ')') {
      parenthesesStack.pop();
      if (parenthesesStack.empty()) {
        break;
      }
    }
  }
  
  return i;
}