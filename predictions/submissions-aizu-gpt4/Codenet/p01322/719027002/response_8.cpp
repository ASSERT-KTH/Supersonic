#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  int n, m;
  unordered_map<string, int> dictionary;
  string word;
  int score, ans;

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    
    dictionary.clear();
    ans = 0;

    for (int i = 0; i < n; ++i) {
      cin >> word >> score;
      dictionary[word] = score;
    }

    for (int i = 0; i < m; ++i) {
      cin >> word;
      if (dictionary.find(word) != dictionary.end()) 
        ans += dictionary[word];
    }

    cout << ans << endl;
  }

  return 0;
}