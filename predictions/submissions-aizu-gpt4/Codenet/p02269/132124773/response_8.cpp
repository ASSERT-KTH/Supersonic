#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else
      cout << (Dic[word] ? "yes\n" : "no\n");
  }
  return 0;
}