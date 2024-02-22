//... other parts of the code

// Avoid unnecessary object initialization
Tree(int sz, int hev[], int hevsm[], int data[]) {
  if (sz == 1) {
    lzdata(data[0]);
    return;
  }
  int sm = hevsm[sz] - hevsm[0];
  int md = lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
  if (md <= 200200)
    md = sz / 2;
  l = new Tree(md, hev, hevsm, data);
  r = new Tree(sz - md, hev + md, hevsm + md, data + md);
  n = merge(l->n, r->n);
}

// Use move semantics in merge()
static Node merge(const Node &l, const Node &r) {
  if (l.sz == 0)
    return r;
  if (r.sz == 0)
    return l;
  Node res(l.sz + r.sz);
  //... other parts of the function
  return std::move(res);
}

// ... other parts of the code

int main2() {
  // ... other parts of the function

  // Use a lookup table to avoid redundant computations
  std::unordered_map<int, Tree::Node> lookup;
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    t = getint();
    a = getint();
    b = getint();
    c = getint();
    a--;
    b--;
    if (t == 1) {
      hl.path_set(a, b, c);
    } else {
      auto key = a * 10000 + b; // create a unique key for a, b pair
      if (lookup.find(key) == lookup.end()) { // if result not in lookup table, compute and store it
        auto n = hl.path_get(a, b);
        lookup[key] = n;
        putint((n.mv < 0) ? n.mv : n.ma);
      } else { // if result in lookup table, reuse it
        auto n = lookup[key];
        putint((n.mv < 0) ? n.mv : n.ma);
      }
      putchar_unlocked('\n');
    }
  }

  return 0;
}

// ... other parts of the code