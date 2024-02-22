// ... other parts of the code remain unchanged ...

node *fix(node *t) {
  if (!t)
    return nullptr;
  int leftDepth = depth(t->ch[0]);
  int rightDepth = depth(t->ch[1]);
  if (leftDepth - rightDepth == 2) {
    if (depth(t->ch[0]->ch[1]) > depth(t->ch[0]->ch[0])) {
      t->ch[0] = rotate(t->ch[0], 0);
    }
    t = rotate(t, 1);
  } else if (leftDepth - rightDepth == -2) {
    if (depth(t->ch[1]->ch[0]) > depth(t->ch[1]->ch[1])) {
      t->ch[1] = rotate(t->ch[1], 1);
    }
    t = rotate(t, 0);
  }
  return t;
}

// ... other parts of the code remain unchanged ...