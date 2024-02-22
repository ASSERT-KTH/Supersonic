#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, s, a, result;
  vector<long long> j;

  while (true) {
    cin >> n;
    if (!n)
      break;

    j.resize(n);
    for (long long i = 0, s = 0; i < n; ++i) {
      cin >> a;
      s += a;
      if (i != 0)
        cin >> j[i];
    }

    sort(j.begin(), j.end());

    result = n * s;
    for (long long i = n - 1; i > 0; --i) {
      s -= j[i];
      result = max(result, i * s);
    }

    cout << result << endl;
  }

  return 0;
}