#include <algorithm>
#include <vector>
#include <tuple>
#include <iostream>

struct HLComp_Y {
    std::vector<std::vector<int>> g;
    std::vector<std::pair<int, int>> n2l;
    int lc, nc;
    std::vector<Tree*> li;
    std::vector<std::pair<int, int>> l2p;
    std::vector<int> sz;
    std::vector<int> data;
    std::vector<int> buf;
    std::vector<int> bufsm;
    std::vector<int> bufdata;
    std::vector<int> ldps;

    struct Tree {
        struct Node {
            Node(int sz = 0) : sz(sz), lzf(false) {}
            int sz;
            int d, sm, lz;
            int lsm, rsm, ma, mv;
            bool lzf;
        } n;

        Tree() {}
        Tree(int sz, int hev[], int hevsm[], int data[]) : n(sz) {
            if (sz == 1) {
                lzdata(data[0]);
                return;
            }
            int sm = hevsm[sz] - hevsm[0];
            int md = std::lower_bound(hevsm, hevsm + sz - 1, sm / 2 + hevsm[0]) - hevsm;
            if (md <= 200200)
                md = sz / 2;
            l = new Tree(md, hev, hevsm, data);
            r = new Tree(sz - md, hev + md, hevsm + md, data + md);
            n = merge(l->n, r->n);
        }
        
        void lzdata(int d) {
            n.d = n.mv = d;
            n.sm = n.sz * d;
            n.lsm = n.rsm = n.ma = std::max(0, n.sm);
            n.lz = d;
            n.lzf = true;
        }

        void push() {
            if (n.sz == 1)
                return;
            if (n.lzf) {
                std::stack<Tree*> stack;
                stack.push(this);
                while (!stack.empty()) {
                    Tree* node = stack.top();
                    stack.pop();
                    node->l->lzdata(node->n.lz);
                    node->r->lzdata(node->n.lz);
                    node->n.lzf = false;
                    if (node->l->n.sz > 1)
                        stack.push(node->l);
                    if (node->r->n.sz > 1)
                        stack.push(node->r);
                }
            }
        }

        static Node merge(const Node &l, const Node &r) {
            if (l.sz == 0)
                return r;
            if (r.sz == 0)
                return l;
            Node res(l.sz + r.sz);
            res.sm = l.sm + r.sm;
            res.lsm = std::max(l.lsm, l.sm + r.lsm);
            res.rsm = std::max(r.rsm, r.sm + l.rsm);
            res.ma = std::max(std::max(l.ma, r.ma), l.rsm + r.lsm);
            res.mv = std::max(l.mv, r.mv);
            return res;
        }
        
        static Node rev(Node u) {
            std::swap(u.lsm, u.rsm);
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
            std::stack<Tree*> stack;
            stack.push(this);
            while (!stack.empty()) {
                Tree* node = stack.top();
                stack.pop();
                node->l->set(a, b, x);