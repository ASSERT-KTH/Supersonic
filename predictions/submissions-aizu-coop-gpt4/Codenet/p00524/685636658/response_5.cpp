// headers and typedefs omitted for brevity

unordered_map<pi, int> v2id; // changed map to unordered_map

int main() {
  // input reading omitted for brevity

  auto insert_node = [&](int v, int h) -> int {
    auto res = v2id.insert({pi(v, h), ct});
    if (res.second) {
      height[v].insert(h);
      ct++;
    }
    return res.first->second;
  };

  int start = insert_node(0, X);
  int goal = insert_node(n - 1, H[n - 1]);

  for (const auto &p : v2id) {
    int v = p.first.first, h = p.first.second;
    auto it = height[v].upper_bound(h);
    if (it != height[v].end()) {
      int nh = *it;
      int nv = v2id[pi(v, nh)];
      int dist = nh - h;
      gg[p.second].pb({nv, dist});
      gg[nv].pb({p.second, dist});
    }
  }
  
  // rest of the code omitted for brevity
}