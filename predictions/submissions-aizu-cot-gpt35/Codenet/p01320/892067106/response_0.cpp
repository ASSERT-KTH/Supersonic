#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct MSQ {
  vector<pii> seg;
  int m, k;

  MSQ(int m, int k) : m(m), k(k) {
    for (int i = 0; i < m; i++) {
      seg.emplace_back(i, (i + k) % m);
    }
  }

  bool check(R r, const vector<pii>& shoolack, int i, int j) {
    pii l = seg[j];
    pii gp = make_pair(shoolack[i].first - l.first * r,