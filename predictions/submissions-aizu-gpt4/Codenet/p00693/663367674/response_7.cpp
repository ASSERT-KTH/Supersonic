#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

struct Data {
  string from, to, message;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  while (cin >> N >> M, N || M) {
    vector<pair<string, string>> OK, NOT;
    for (int i = 0; i < N; i++) {
      string buf, from, to;
      cin >> buf >> from >> to;
      if (buf[0] == 'p') {
        OK.emplace_back(from, to);
      } else {
        NOT.emplace_back(from, to);
      }
    }
    unordered_set<int> erasedOK, erasedNOT;
    for (int i = NOT.size() - 1; i >= 0; i--) {
      for (int k = OK.size() - 1; k >= 0; k--) {
        if (i < k || erasedOK.count(k))
          continue;
        if (NOT[i] == OK[k]) {
          erasedOK.insert(k);
        }
      }
    }
    for (int i = OK.size() - 1; i >= 0; i--) {
      for (int k = NOT.size() - 1; k >= 0; k--) {
        if (i < k || erasedNOT.count(k))
          continue;
        if (OK[i] == NOT[k]) {
          erasedNOT.insert(k);
        }
      }
    }
    queue<Data> Q;
    for (int loop = 0; loop < M; loop++) {
      Data data;
      cin >> data.from >> data.to >> data.message;
      bool isOK = false, isNOT = false;
      for (int i = 0; i < OK.size(); i++) {
        if (erasedOK.count(i))
          continue;
        if (OK[i].first.find(data.from) != string::npos &&
            OK[i].second.find(data.to) != string::npos) {
          isOK = true;
          break;
        }
      }
      for (int i = 0; i < NOT.size(); i++) {
        if (erasedNOT.count(i))
          continue;
        if (NOT[i].first.find(data.from) != string::npos &&
            NOT[i].second.find(data.to) != string::npos) {
          isNOT = true;
          break;
        }
      }
      if (isOK && !isNOT) {
        Q.push(data);
      }
    }
    cout << Q.size() << "\n";
    while (!Q.empty()) {
      cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << "\n";
      Q.pop();
    }
  }
  return 0;
}