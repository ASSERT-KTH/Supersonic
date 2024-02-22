stack<int> stack;
while (y < n && x < s.size()) {
  if (isdigit(expr[x])) {
    stack.push(expr[x] - '0');
    x++;
  } else if (expr[x] == '+' || expr[x] == '*') {
    char op = expr[x];
    x++;
    vector<int> term;
    while (!stack.empty()) {
      term.push_back(stack.top());
      stack.pop();
    }
    if (op == '+')
      stack.push(accumulate(all(term), 0));
    else
      stack.push(accumulate(all(term), 1, multiplies<int>()));
  }
}
cout << stack.top() << endl;