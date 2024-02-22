// Function splay with reduced redundant computations
void splay() {
  node_t *x = this, *pp;
  Monoid per_recalc;
  while (!x->isroot()) {
    if (per->isroot()) {
      if (per->left == this) {
        per->left = right;
        per_recalc = per->recalc();
        right = per;
      } else {
        per->right = left;
        per_recalc = per->recalc();
        left = per;
      }
      x = per;
      per = per->per;
      recalc();
      break;
    }
    x = per->per;
    pp = x->per;
    if (per->left == this) {
      if (x->left == per) {
        x->left = per->right;
        per->left = right;
        per->right = x;
        right = per;
      } else {
        x->right = left;
        per->left = right;
        right = per;
        left = x;
      }
    } else {
      if (x->right == per) {
        x->right = per->left;
        per->right = left;
        per->left = x;
        left = per;
      } else {
        x->left = right;
        per->right = left;
        left = per;
        right = x;
      }
    }
    x->recalc();
    per_recalc = per->recalc();
    recalc();
    per = pp;
    if (pp) {
      if (pp->left == x) {
        pp->left = this;
      } else if (pp->right == x) {
        pp->right = this;
      }
    }
  }
  x->b |= 4;
}

// Function expose without unnecessary function calls
void expose(node_t *prev) {
  splay();
  right->b &= ~4;
  right = prev;
  recalc();
  if (per)
    per->expose(this);
  else {
    b &= ~4;
  }
}

// Function evert without unnecessary function calls
void evert(uint32 v) {
  expose(&tree[v]);
  tree[v].b ^= 2;
}

// Removed std::vector<vis> v and scan function