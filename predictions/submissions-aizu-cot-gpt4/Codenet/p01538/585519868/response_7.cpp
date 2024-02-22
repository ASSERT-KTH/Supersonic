#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Q, N, count, tmp, max, S;
  bool FLG;
  cin >> Q;
  bool *table = new bool[1000001];
  vector<int> encountered;
  for (int loop = 0; loop < Q; loop++) {
    encountered.clear();
    count = 0;
    cin >> N;
    table[N] = true;
    encountered.push_back(N);
    FLG = false;
    while (N / 10 != 0) {
      max = 0;
      S = pow(10, to_string(N).size() / 2);
      while (S != 0) {
        tmp = (N / S) * (N % S);
        max = max >= tmp ? max : tmp;
        S /= 10;
      }
      N = max;
      if (table[N] == true) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        encountered.push_back(N);
        count++;
      }
    }
    if (FLG) {
      cout << "-1\n";
    } else {
      cout << count << "\n";
    }
    for (int i = 0; i < encountered.size(); i++)
      table[encountered[i]] = false;
  }
  delete[] table;
  return 0;
}