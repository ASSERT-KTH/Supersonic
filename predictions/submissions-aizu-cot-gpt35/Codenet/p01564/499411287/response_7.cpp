#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <valarray>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct Tree {
    typedef Tree* NP;
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
        stack<pair<Tree*, int>> s;
        s.push(make_pair(this, sz));
        while (!s.empty()) {
            auto [t, sz] = s.top();
            s.pop();
            if (sz == 1) {
                t->lzdata(data[0]);
                continue;
            }
            int sm = hevsm[sz] - hevsm[0];
            int md = lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
            if (md <= 200200)
                md = sz / 2;
            t->l = new Tree(md, hev, hevsm, data);
            t->r = new Tree(sz - md, hev + md, hevsm + md, data + md);
            t->n = merge(t->l->n, t->r->n);
            s.push(make_pair(t->r, sz - md));
            s.push(make_pair(t->l, md));
        }
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
    static Node merge(const Node& l, const Node& r) {
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
        stack<pair<Tree*, int>> s;
        s.push(make_pair(this, a));
        while (!s.empty()) {
            auto [t, a] = s.top();
            s.pop();
            if (t->n.sz <= b) {
                t->lzdata(x);
                continue;
            }
            t->push();
            s.push(make_pair(t->r, a - t->l->n.sz));
            s.push(make_pair(t->l, a));
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
        stack<pair<Tree*, int>> s;
        s.push(make_pair(this, a));
        Node res;
        while (!s.empty()) {
            auto [t, a] = s.top();
            s.pop();
            if (t->n.sz <= b) {
                res = merge(res, t->n);
                continue;
            }
            t->push();
            s.push(make_pair(t->r, a - t->l->n.sz));
            s.push(make_pair(t->l, a));
        }
        return res;
    }
};
template <int N>
struct HLComp_Y {
    vector<int> g[N];
    void add(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    P n2l[N];
    int lc, nc;
    Tree* li[N];
    P l2p[N];
    int sz[N];
    int data[N];
    int buf[N];
    int bufsm[N];
    int bufdata[N];
    int ldps[N];
    void dfs_sz(int p, int b) {
        sz[p] = 1;
        for (int d : g[p]) {
            if (d == b)
                continue;
            dfs_sz(d, p);
            sz[p] += sz[d];
        }
    }
    void dfs(int p, int b) {