#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<string, bool> Dic;
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
}
