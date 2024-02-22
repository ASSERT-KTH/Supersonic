int get_boss(int id) {
  int parent = boss[id];
  while (parent != id) {
    id = parent;
    parent = boss[id];
  }
  return id;
}