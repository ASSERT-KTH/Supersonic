#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unordered_map<string, bool> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic.insert({word, true});
    else
      cout << (Dic.find(word) != Dic.end() ? "yes\n" : "no\n");
  }
}