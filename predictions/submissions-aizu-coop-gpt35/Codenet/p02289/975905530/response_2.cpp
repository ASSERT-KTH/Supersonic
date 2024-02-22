#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int pop_and_print(vector<int>& qu) {
  cout << qu[0] << endl;
  qu.erase(qu.begin());
  return 0;
}

int main() {
  string s;
  int inp;
  vector<int> qu;

  do {
    cin >> s;

    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      auto it = lower_bound(qu.begin(), qu.end(), inp, greater<int>());
      qu.insert(it, inp);
    } else {
      pop_and_print(qu);
    }
  } while (s != "end");

  return 0;
}