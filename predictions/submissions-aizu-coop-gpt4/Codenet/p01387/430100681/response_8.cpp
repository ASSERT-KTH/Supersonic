Node *merge(Node *l, Node *r) {
  if (!l || !r)
    return l ? l : r;
  
  int l_count = count(l);
  int r_count = count(r);
  if (xor128() % (l_count + r_count) < l_count) {
    l = propagete(l);
    l->r = merge(l->r, r);
    return update(l);
  } else {
    r = propagete(r);
    r->l = merge(l, r->l);
    return update(r);
  }
}