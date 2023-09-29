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
    switch(com[0]) {
      case 'i':
        Dic[word] = true;
        break;
      default:
        cout << (Dic[word] ? "yes\n" : "no\n");
        break;
    }
  }
}