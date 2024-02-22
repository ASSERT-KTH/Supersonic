#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, bool> dic;
  int n;
  string opstr, str;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr == "insert") {
      dic[str] = true;
    } else if (opstr == "find") {
      if (dic.find(str) != dic.end())
        cout << "yes" << "\n";
      else
        cout << "no" << "\n";
    }
  }
  return 0;
}