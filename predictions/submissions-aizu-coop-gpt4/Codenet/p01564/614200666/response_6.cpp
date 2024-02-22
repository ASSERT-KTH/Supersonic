// ... (initial part of the code remains the same)
void expose() {
    assert(this != last);
    NP u = this;
    NP prev = NULL;
    do {
      if(u != prev) {
        u->splay();
        prev = u;  // Keep track of the previously splayed node
      }
    } while ((u = u->p));
    
    u = last;
    u->p = this;
    do {
      u->p->r = u;
      NP updatedNode = u->p->update();
      u = updatedNode;
    } while (u->p);
    splay();
}
// ... (rest of the code remains the same)