#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
struct LCNode {

  // (rest of the struct definition remains the same)

  NP update() {
    assert(this != last);
    sz = 1 + l->sz + r->sz;
    sm = v + l->sm + r->sm;
    lsm = max(l->lsm, l->sm + v + r->lsm);
    rsm = max(r->rsm, r->sm + v + l->rsm);
    int temp = max(l->rsm + v + r->lsm, max(l->ma, r->ma)); // Store result in a variable
    ma = temp;
    mv = max(v, max(l->mv, r->mv));
    return this;
  }

  // (rest of the struct definition remains the same)
};
// (rest of the code remains the same)