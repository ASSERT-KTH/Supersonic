#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int color, par, depth, top;
};

int solve(int u, int v, const vector<Node>& nodes) {
  while (nodes[u].color != nodes[v].color) {
    if (nodes[nodes[u].top].depth > nodes[nodes[v].top].depth)
      u = nodes[u].par;
    else
      v = nodes[v].par;
  }
  while (u != v) {
    if (nodes[u].depth > nodes[v].depth)
      u = nodes[u].par;
    else
      v = nodes[v].par;
  }
  return u;
}

void decomp(int root, const vector<vector<int>>& tree, vector<Node>& nodes) {
  int n = tree.size();
  vector<int> tord;
  stack<int> st;
  st.push(root);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    tord.push_back(v);
    for (int c : tree[v]) {
      if (nodes[c].par == -1) {
        st.push(c);
        nodes[c].par = v;
        nodes[c].depth = nodes[v].depth + 1;
      }
    }
  }
  int c = 0;
  for (int u : tord) {
    if (nodes[u].color != -1)
      continue;
    stack<int> st;
    st.push(u);
    int k = 0;
    while (!st.empty() && k < B) {
      int v = st.top();
      st.pop();
      nodes[v].color = c;
      nodes[v].top = u;
      k++;
      for (int c : tree[v]) {
        if (nodes[c].color == -1)
          st.push(c);
      }
    }
    c++;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      tree[i].push_back(c);
    }
  }
  vector<Node> nodes(n, {-1, -1, 0, 0});
  decomp(0, tree, nodes);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v, nodes) << endl;
  }
}