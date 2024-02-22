node *insert(int k, T v) {
    node *t = root;
    while (t) {
        int c = count(t->ch[0]);
        if (k <= c) {
            t = t->ch[0];
        } else {
            k -= c + 1;
            t = t->ch[1];
        }
    }
    t = new node(v);
    fix(t);  // This needs to be updated to work iteratively too
    return t;
}