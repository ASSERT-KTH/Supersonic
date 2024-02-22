#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // Optimizing I/O operations
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  unordered_map<string, bool> Dic; // Using unordered_map instead of map
  string com, word;
  while (n--) {
    cin >> com >> word;
    if (com.front() == 'i') // Using char comparison instead of string comparison
      Dic[word] = true;
    else {
      if (Dic[word])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
}