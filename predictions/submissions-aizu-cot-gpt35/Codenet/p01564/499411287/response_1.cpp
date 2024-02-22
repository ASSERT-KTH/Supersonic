#include <cstdio>
#include <vector>
using namespace std;

struct Tree {
    struct Node {
        Node(int sz = 0) : sz(sz), lzf(false) {}
        int sz;
        int d, sm, lz;
        int lsm, rsm, ma, mv;
        bool lzf;
    } n;
    Tree *l, *r;

    Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz) {
        if (sz == 1) {
            lzdata(data[0]);
            return;
        }
        int sm = hevsm[sz] - hevsm[0];
        int md = lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
        if (md <= 200200)
            md = sz / 2;

        l = new Tree(md, hev, hevsm, data);
        r = new Tree(sz - md, hev + md, hevsm + md, data + md);
        n = merge(l->n, r->n);
    }

    void lzdata(int d) {
        n.d = n.mv = d;
        n.sm = n.sz * d;
        n.lsm = n.rsm = n.ma = max(0, n.sm);
        n.lz = d;
        n.lzf = true;
    }

    void push() {
        if (n.sz == 1)
            return;
        if (n.lzf) {
            l->lzdata(n.lz);
            r->lzdata(n.lz);
            n.lzf = false;
        }
    }

    static Node merge(const Node &l, const Node &r) {
        if (l.sz == 0)
            return r;
        if (r.sz == 0)
            return l;
        Node res(l.sz + r.sz);
        res.sm = l.sm + r.sm;
        res.lsm = max(l.lsm, l.sm + r.lsm);
        res.rsm = max(r.rsm, r.sm + l.rsm);
        res.ma = max(max(l.ma, r.ma), l.rsm + r.lsm);
        res.mv = max(l.mv, r.mv);
        return res;
    }

    static Node rev(Node u) {
        swap(u.lsm, u.rsm);
        return u;
    }

    void set(int a, int b, int x) {
        if (b <= 0 || n.sz <= a) {
            return;
        }
        push();
        if (a <= 0 && n.sz <= b) {
            lzdata(x);
            return;
        }

        Tree *tl = l;
        Tree *tr = r;
        while (true) {
            if (a < tl->n.sz) {
                tl->set(a, min(b, tl->n.sz), x);
                break;
            } else {
                a -= tl->n.sz;
                b -= tl->n.sz;
                tl->push();
                tr->push();
                tl = tl->r;
                tr = tr->r;
            }
        }

        n = merge(l->n, r->n);
    }

    Node get(int a, int b) {
        if (b <= 0 || n.sz <= a) {
            return Node();
        }
        push();
        if (a <= 0 && n.sz <= b) {
            return n;
        }

        Tree *tl = l;
        Tree *tr = r;
        Node res;
        while (true) {
            if (a < tl->n.sz) {
                res = merge(res, tl->get(a, min(b, tl->n.sz)));
                break;
            } else {
                a -= tl->n.sz;
                b -= tl->n.sz;
                tl->push();
                tr->push();
                tl = tl->r;
                tr = tr->r;
            }
        }

        return merge(res, tr->get(a, b));
    }
};

struct HLComp_Y {
    vector<int> g[220100];
    vector<Tree*> &li;
    vector<int> &data;
    vector<pair<int, int>> &n2l;
    vector<pair<int, int>> &l2p;
    vector<int> &ldps;
    vector<int> &sz;
    int lc, nc;

    HLComp_Y(vector<Tree*> &li, vector<int> &data, vector<pair<int, int>> &n2l, vector<pair<int, int>> &l2p, vector<int> &ldps, vector<int> &sz)
        : li(li), data(data), n2l(n2l), l2p(l2p), ldps(ldps), sz(sz) {}

    void add(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfs_sz(int p, int b) {
        sz[p] = 1;
        for (int d : g[p]) {
            if (d == b)
                continue;
            dfs_sz(d, p);