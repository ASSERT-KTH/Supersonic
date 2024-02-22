#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int S[MAX];

struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data &d) const {
    if (score != d.score)
      return score < d.score;
    return num > d.num;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  // Use vector to implement max heap
  vector<data> Q;
  Q.push_back(data(0, 0));
  make_heap(Q.begin(), Q.end());
  
  data temp;  // Reusable temp data object
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    
    temp.num = a;
    temp.score = S[a];
    Q.push_back(temp);
    push_heap(Q.begin(), Q.end());
    
    while (1) {
      temp = Q.front();  // Get the top element
      if (temp.score == S[temp.num]) {
        cout << temp.num << " " << temp.score << endl;
        break;
      }
      pop_heap(Q.begin(), Q.end());  // Only pop if condition is not satisfied
      Q.pop_back();
    }
  }
  return 0;
}