//... rest of the code remains same
struct Tree {
typedef shared_ptr<Tree> NP;
NP l, r;

struct Node {
    Node(int sz = 0) : sz(sz), lzf(false) {}
    int sz;
    int d, sm, lz;
    int lsm, rsm, ma, mv;
    bool lzf;
} n;

Tree() {}

Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz) {
    //... rest of the code remains same
    l = make_shared<Tree>(md, hev, hevsm, data);
    r = make_shared<Tree>(sz - md, hev + md, hevsm + md, data + md);
    n = merge(l->n, r->n);
}

//... rest of the code remains same

static Node merge(const Node &l, const Node &r) {
    if (l.sz == 0)
        return r;
    if (r.sz == 0)
        return l;
    Node res(l.sz + r.sz);
    res.sm = l.sm + r.sm;
    int l_sm_plus_r_lsm = l.sm + r.lsm;
    int r_sm_plus_l_rsm = r.sm + l.rsm;
    res.lsm = max(l.lsm, l_sm_plus_r_lsm);
    res.rsm = max(r.rsm, r_sm_plus_l_rsm);
    res.ma = max({l.ma, r.ma, l.rsm + r.lsm});
    res.mv = max(l.mv, r.mv);
    return res;
}

static Node rev(Node &u) {
    swap(u.lsm, u.rsm);
    return u;
}

//... rest of the code remains same

};