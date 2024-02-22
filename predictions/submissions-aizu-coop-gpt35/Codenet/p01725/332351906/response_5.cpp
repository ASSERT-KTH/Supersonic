#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string S;
int p;
stack<ll> nums;
stack<char> ops;

ll calc() {
  ll res = 0;
  ll num = 0;
  char op = '+';

  while (p < S.size()) {
    if (isdigit(S[p])) {
      num = num * 10 + S[p] - '0';
      p++;
    } else if (S[p] == '(') {
      p++;
      num = calc();
    } else {
      if (op == '+')
        res += num;
      else if (op == '-')
        res -= num;
      else if (op == '*')
        res *= num;

      num = 0;

      if (S[p] == ')') {
        p++;
        break;
      }

      op = S[p];
      p++;
    }
  }

  if (op == '+')
    res += num;
  else if (op == '-')
    res -= num;
  else if (op == '*')
    res *= num;

  return res;
}

int main() {
  cin >> S;
  ll res = calc();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ll tempRes = res;
        p = 0;

        while (!nums.empty())
          nums.pop();
        while (!ops.empty())
          ops.pop();

        ops.push('#');
        nums.push(tempRes);

        while (p < S.size()) {
          if (isdigit(S[p])) {
            nums.push(S[p] - '0');
            p++;
          } else if (S[p] == '(') {
            nums.push(calc());
          } else {
            char op = S[p];
            p++;

            while (ops.top() != '#' && ((op == '*' && ops.top() == '+') || (op == '*' && ops.top() == '-'))) {
              ll b = nums.top();
              nums.pop();
              ll a = nums.top();
              nums.pop();
              char c = ops.top();
              ops.pop();

              if (c == '+')
                nums.push(a + b);
              else if (c == '-')
                nums.push(a - b);
              else if (c == '*')
                nums.push(a * b);
            }

            ops.push(op);
          }
        }

        while (ops.top() != '#') {
          ll b = nums.top();
          nums.pop();
          ll a = nums.top();
          nums.pop();
          char c = ops.top();
          ops.pop();

          if (c == '+')
            nums.push(a + b);
          else if (c == '-')
            nums.push(a - b);
          else if (c == '*')
            nums.push(a * b);
        }

        res = max(res, nums.top());
      }
    }
  }

  cout << res << endl;
  return 0;
}