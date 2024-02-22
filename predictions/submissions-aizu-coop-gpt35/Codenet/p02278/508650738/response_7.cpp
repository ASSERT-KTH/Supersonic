struct QuickFind {
  vector<int> r, p;
  vector<set<int>> v; // Use set instead of vector for groups
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i].insert(i); // Insert individual elements into sets
    }
  }
  // Rest of the code remains the same
};