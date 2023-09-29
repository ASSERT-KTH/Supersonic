#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 300;
int color[100010], par[100010], depth[100010];
int top[100010];
int goUp[100010];
bool vis[100010];
int n;
vector<vector<int>> g;
void decomp(int root) {
  rep(i, n) vis[i] = false, par[i] = -1;
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (q.size()) {
    int v = q.front();
    q.pop();
    vis[v] = true;
    tord.push_back(v);
    for (int c : g[v]) {
      if (!vis[c]) {
        q.push(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  rep(i, n) vis[i] = false;
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
    q.push(u);
    int k = 0;
    while (q.size() && k < B) {
      int v = q.front();
      q.pop();
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
