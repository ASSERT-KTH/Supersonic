// ...

// Replace multiple calls to minId(s) and find_root(s) with a single call and store the result in a variable.
node_t *v;
int minId_s;

// ...
while (true) {
  v = find_root(s);
  if (v == t) {
    minId_s = minId(s);
    expose(v = nodes[minId_s]);
    flow += v->mini;
    add(s, -v->mini);
    while (true) {
      minId_s = minId(s);
      expose(v = nodes[minId_s]);
      if (v->val > 0)
        break;
      g[v->e->to][v->e->rev].cap += v->e->cap;
      v->e->cap = 0;
      cut(v);
    }
    continue;
  }

  // ...

}
// ...