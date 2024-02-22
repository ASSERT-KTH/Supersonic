#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> data;
  int n, distinctCount = 0;
  while (distinctCount < 28) {
    cin >> n;
    data.insert(n);
    distinctCount = data.size();
  }

  string missingNumbers;
  for (int i = 1; i <= 30; i++) {
    if (!data.count(i))
      missingNumbers += to_string(i) + " ";
  }

  cout << missingNumbers << endl;
  return 0;
}