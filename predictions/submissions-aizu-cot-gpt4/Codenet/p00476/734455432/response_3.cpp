#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;
typedef pair<int, int> Pr;

vector<int> d, h;
vector<int> seg_v, seg_a;
vector<Pr> rmq;
int size = 1 << 20;

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
//...
}

int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
//...
}

void rmq_update(int k, int x) {
//...
}

Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size) {
//...
}

int rmq_getMax(int l, int r) {
//...
}

int rmq_getMaxIdx(int l, int r) {
//...
}

void solve(int N, int H) {
//...
}

int main() {
  int N, H;
  cin >> N >> H;
  d.resize(N);
  h.resize(N);
  seg_v.resize(size * 2 - 1);
  seg_a.resize(size * 2 - 1);
  rmq.resize(size * 2 - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> d[i+1] >> h[i];
  }
  solve(N, H);
}