#define NDEBUG
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct LCNode {
  int parent;
  int left_child;
  int right_child;
  int size;
  int value;
  int sum;
  int left_sum;
  int right_sum;
  int max_sum;
  int max_value;
  bool reverse;
  int lazy;
  LCNode(int v)
      : parent(-1), left_child(-1), right_child(-1), size(1), value(v), sum(v), left_sum(max(v, 0)), right_sum(max(v, 0)), max_sum(max(v, 0)), max_value(v), reverse(false), lazy(-1) {}
  LCNode() : size(0), value(-1), max_value(-1) {}
};

const int MN = 201000;
LCNode tr[MN];
int parent[MN];
int lazy[MN];
int sum[MN];
int left_sum[MN];
int right_sum[MN];
int max_sum[MN];
int max_value[MN];

void rot(int x) {
  int p = parent[x];
  int g = parent[p];
  int is_root_p = parent[p] == -1;
  int is_left_x = x == tr[p].left_child;
  
  if (!is_root_p) {
    if (p == tr[g].left_child) {
      tr[g].left_child = x;
    } else {
      tr[g].right_child = x;
    }
  }
  
  if (is_left_x) {
    tr[p].left_child = tr[x].right_child;
    if (tr[x].right_child != -1) {
      parent[tr[x].right_child] = p;
    }
    tr[x].right_child = p;
  } else {
    tr[p].right_child = tr[x].left_child;
    if (tr[x].left_child != -1) {
      parent[tr[x].left_child] = p;
    }
    tr[x].left_child = p;
  }
  
  parent[p] = x;
  parent[x] = g;
  
  if (!is_root_p) {
    tr[p].update();
  }
  tr[x].update();
}

void splay(int x) {
  while (parent[x] != -1) {
    int p = parent[x];
    int g = parent[p];
    
    if (g != -1) {
      if ((x == tr[p].left_child) == (p == tr[g].left_child)) {
        rot(p);
      } else {
        rot(x);
      }
    }
    
    rot(x);
  }
}

void expose(int x) {
  int u = x;
  int v = -1;
  
  while (u != -1) {
    splay(u);
    tr[u].reverse_data();
    tr[u].right_child = v;
    tr[u].update();
    v = u;
    u = parent[u];
  }
  
  splay(x);
}

void push(int x) {
  if (tr[x].reverse) {
    if (tr[x].left_child != -1) {
      tr[tr[x].left_child].reverse_data();
    }
    if (tr[x].right_child != -1) {
      tr[tr[x].right_child].reverse_data();
    }
    tr[x].reverse = false;
  }
  if (lazy[x] != -1) {
    if (tr[x].left_child != -1) {
      tr[tr[x].left_child].lazy_data(lazy[x]);
    }
    if (tr[x].right_child != -1) {
      tr[tr[x].right_child].lazy_data(lazy[x]);
    }
    lazy[x] = -1;
  }
}

void reverse_data(int x) {
  swap(tr[x].left_child, tr[x].right_child);
  swap(tr[x].left_sum, tr[x].right_sum);
  tr[x].reverse = !tr[x].reverse;
}

void lazy_data(int x, int d) {
  tr[x].value = d;
  tr[x].sum = tr[x].size * d;
  tr[x].left_sum = tr[x].right_sum = tr[x].max_sum = max(0, tr[x].sum);
  tr[x].max_value = d;
  lazy[x] = d;
}

void update(int x) {
  tr[x].size = 1 + (tr[x].left_child != -1 ? tr[tr[x].left_child].size : 0) + (tr[x].right_child != -1 ? tr[tr[x].right_child].size : 0);
  tr[x].sum = tr[x].value + (tr[x].left_child != -1 ? tr[tr[x].left_child].sum : 0) + (tr[x].right_child != -1 ? tr[tr[x].right_child].sum : 0);
  tr[x].left_sum = max((tr[x].left_child != -1 ? tr[tr[x].left_child].left_sum : 0), (tr[x].left_child != -1 ? tr[tr[x].left_child].sum : 0) + tr[x].value + (tr[x].right_child != -1 ? tr[tr[x].right_child].left_sum : 0));
  tr[x].right_sum = max((tr[x].right_child != -1 ? tr[tr[x].right_child].right_sum : 0), (tr[x].right_child != -1 ? tr[tr[x].right_child].sum : 0) + tr[x].value + (tr[x].left_child != -1 ? tr[tr[x].left_child].right_sum : 0));
  tr[x].max_sum = max((tr[x].left_child != -1 ? tr[tr[x].left_child].right_sum : 0) + tr[x].value + (tr[x].right_child != -1 ? tr[tr[x].right_child].left_sum : 0), max((tr[x].left_child != -1 ? tr[tr[x].left_child].max_sum : 0), (tr[x].right_child != -1 ? tr[tr[x].right_child].max_sum : 0)));
  tr[x].max_value = max(tr[x].value, max((tr[x].left_child != -1 ? tr[tr[x].left_child].max_value : 0), (tr[x].right_child != -1 ? tr[tr[x].right_child].max_value : 0)));
}

void evert(int x) {
  expose(x);
  reverse_data(x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q;
  cin >> n >> q;
  