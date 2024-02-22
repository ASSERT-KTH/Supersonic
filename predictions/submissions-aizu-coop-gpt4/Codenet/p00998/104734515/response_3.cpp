struct NodePair {
  node *first, *second;
};

NodePair split(node *t, int k) {
  NodePair s;
  if (!t)
    return {nullptr, nullptr};
  if (k <= count(t->left)) {
    s = split(t->left, k);
    t->left = s.second;
    return {s.first, update(t)};
  } else {
    s = split(t->right, k - count(t->left) - 1);
    t->right = s.first;
    return {update(t), s.second};
  }
}