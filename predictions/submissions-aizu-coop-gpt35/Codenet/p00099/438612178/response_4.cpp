#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
const int MAX = 1000001;
typedef pair<int, int> data;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data, vector<data>, less<data>> Q;
  map<int, int> S;
  Q.push(make_pair(0, 0));
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(make_pair(a, S[a]));
    while (!Q.empty()) {
      data now = Q.top();
      if (now.second == S[now.first]) {
        cout << now.first << " " << now.second << endl;
        break;
      }
      Q.pop();
    }
  }
  return 0;
}