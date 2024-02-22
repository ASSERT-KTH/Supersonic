#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false); // Improving efficiency of cin and cout
  cin.tie(NULL);

  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;

    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }

    int vecSize = vec.size(); // Storing size of vector before loop
    for (int i = 0; i < vecSize; i++) {
      if (m[vec[i]] >= 1000000) { // Directly accessing map element
        s = 1;
        cout << vec[i] << "\n";
      }
    }

    if (!s)
      cout << "NA" << "\n";
  }

  return 0;
}