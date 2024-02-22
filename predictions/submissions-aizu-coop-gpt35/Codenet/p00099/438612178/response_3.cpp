#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
const int MAX = 1000001;

struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  // Removed unnecessary comparison
  bool operator<(const data &d) const {
    return score < d.score;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Use unordered_map instead of array for efficient memory usage
  unordered_map<int, int> S;
  
  // Preallocate memory for the hash map and priority queue
  S.reserve(n);
  priority_queue<data> Q;
  Q.reserve(n);

  Q.push(data(0, 0));

  int prevMaxScore = 0; // Store the previous maximum score

  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));

    // Optimize the loop to find the maximum score
    while (Q.top().score != prevMaxScore) {
      Q.pop();
    }

    // Update the previous maximum score
    prevMaxScore = Q.top().score;

    // Print the current maximum number and score
    cout << Q.top().num << " " << Q.top().score << endl;
  }

  return 0;
}