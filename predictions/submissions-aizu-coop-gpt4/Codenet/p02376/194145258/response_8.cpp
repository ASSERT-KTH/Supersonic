// Reserve space for the vector before adding elements
vector<edge> g[max_n];
for(int i=0; i<max_n; i++)
    g[i].reserve(max_n);

// Use a memory pool to allocate nodes
node_t nodePool[max_n];
int nodePoolIndex = 0;
...
// inside max_flow function
for (int i = 0; i < n; i++)
    nodes[i] = &nodePool[nodePoolIndex++];

// Simplify recursive function with iterative approach
void splay() {
    while (!is_root()) {
      if (pp->is_root())
        pp->lp == this ? rotr() : rotl();
      else if (pp->pp->lp == pp)
        pp->lp == this ? (pp->rotr(), rotr()) : (rotl(), rotr());
      else
        pp->rp == this ? (pp->rotl(), rotl()) : (rotr(), rotl());
    }
    push();
    update();
}

// Use inline keyword for small functions
inline void apply(int v) { lazy += v, val += v, mini += v; }
inline void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
}