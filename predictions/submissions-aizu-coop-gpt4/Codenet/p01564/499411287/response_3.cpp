  // ...
  void path_set(int u, int v, int d) {
    int xl, xp;
    tie(xl, xp) = n2l[u];
    int yl, yp;
    tie(yl, yp) = n2l[v];
    int lc = (xl == yl) ? min(xp, yp) : lca_line(u, v);
    while (xl != lc) {
      li[xl]->set(0, xp + 1, d);
      tie(xl, xp) = l2p[xl];
    }
    while (yl != lc) {
      li[yl]->set(0, yp + 1, d);
      tie(yl, yp) = l2p[yl];
    }
    if (xp > yp) {
      li[xl]->set(yp, xp + 1, d);
    } else {
      li[yl]->set(xp, yp + 1, d);
    }
  }
  Tree::Node path_get(int u, int v) {
    int xl, xp;
    tie(xl, xp) = n2l[u];
    int yl, yp;
    tie(yl, yp) = n2l[v];
    int lc = (xl == yl) ? min(xp, yp) : lca_line(u, v);
    Tree::Node nl, nr;
    while (xl != lc) {
      nl = Tree::merge(li[xl]->get(0, xp + 1), nl);
      tie(xl, xp) = l2p[xl];
    }
    while (yl != lc) {
      nr = Tree::merge(li[yl]->get(0, yp + 1), nr);
      tie(yl, yp) = l2p[yl];
    }
    if (xp > yp) {
      nl = Tree::merge(li[xl]->get(yp, xp + 1), nl);
    } else {
      nr = Tree::merge(li[yl]->get(xp, yp + 1), nr);
    }
    nl = Tree::rev(nl);
    return Tree::merge(nl, nr);
  }
  // ...