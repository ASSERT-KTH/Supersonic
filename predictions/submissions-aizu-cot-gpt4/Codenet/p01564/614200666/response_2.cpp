// Rest of the code remains the same until here...

void expose() {
  assert(this != last);
  NP u = this, rr = NULL;
  do {
    u->splay();
    u->r = rr;
    rr = u;
    u = u->p;
  } while (u);
  splay();
}

void splay() {
  assert(this != last);
  supush();
  while (p) {
    if (!p->p) {
      p->push(), push();
      if (p->l == this) rot();
      else rot();
    } else {
      p->p->push(), p->push(), push();
      bool flag = p->p->l == p;
      if (flag == (p->l == this)) {
        if (flag) p->rot();
        else rot();
      } else {
        if (flag) rot();
        else p->rot();
      }
    }
  }
  update();
}

// Rest of the code remains the same until here...