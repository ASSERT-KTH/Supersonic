#include <iostream>

using namespace std;

typedef long long ll;

struct LCNode {
    struct Node {
        Node *p, *l, *r;
        int sz, v, sm, lz, lsm, rsm, ma, mv;
        bool rev;

        Node(int v)
            : p(nullptr), l(nullptr), r(nullptr), sz(1), v(v), sm(v), lz(0), rev(false),
            lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}

        void update() {
            sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
            sm = v + (l ? l->sm : 0) + (r ? r->sm : 0);
            lsm = max((l ? l->lsm : 0), (l ? l->sm : 0) + v + max((r ? r->lsm : 0), 0));
            rsm = max((r ? r->rsm : 0), (r ? r->sm : 0) + v + max((l ? l->rsm : 0), 0));
            ma = max((l ? l->rsm : 0) + v + (r ? r->lsm : 0), max((l ? l->ma : 0), (r ? r->ma : 0)));
            mv = max(v, max((l ? l->mv : 0), (r ? r->mv : 0)));
        }
    };

    Node* makeNode(int v) {
        Node* node = new Node(v);
        return node;
    }

    void rot(Node* x) {
        Node* p = x->p;
        Node* g = p->p;
        if (g) {
            if (g->l == p) g->l = x;
            else g->r = x;
        }
        if (p->l == x) {
            p->l = x->r;
            if (x->r) x->r->p = p;
            x->r = p;
        } else {
            p->r = x->l;
            if (x->l) x->l->p = p;
            x->l = p;
        }
        p->p = x;
        x->p = g;
        p->update();
        x->update();
    }

    void splay(Node* x) {
        while (x->p) {
            Node* p = x->p;
            Node* g = p->p;
            if (g) {
                if ((g->l == p) == (p->l == x)) rot(p);
                else rot(x);
            }
            rot(x);
        }
    }

    void expose(Node* x) {
        splay(x);
        if (x->r) {
            x->r->p = nullptr;
            x->r->rev = true;
            x->r->lz = x->v;
            x->r->v = x->v;
            x->r->sm = x->r->sz * x->v;
            x->r->lsm = x->r->rsm = x->r->ma = max(x->v, x->r->sm);
            x->r->mv = x->v;
            x->r->update();
            x->r = nullptr;
            x->update();
        }
    }

    void link(Node* child, Node* parent) {
        expose(child);
        child->p = parent;
    }

    void cut(Node* child) {
        expose(child);
        child->l->p = nullptr;
        child->l = nullptr;
        child->update();
    }

    int query(Node* x, Node* y) {
        expose(x);
        expose(y);
        return y->ma;
    }
};

const int MN = 201000;
LCNode::Node tr[MN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        tr[i] = LCNode::Node(w);
    }

    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        LCNode::link(&tr[s], &tr[e]);
    }

    for (int i = 0; i < q; i++) {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        a--;
        b--;

        if (t == 1) {
            tr[a].expose(&tr[a]);
            tr[b].expose(&tr[b]);
            tr[b].lz = c;
            tr[b].v = c;
            tr[b].sm = tr[b].sz * c;
            tr[b].lsm = tr[b].rsm = tr[b].ma = max(c, tr[b].sm);
            tr[b].mv = c;
            tr[b].update();
        } else {
            int d = tr[a].query(&tr[a], &tr[b]);
            cout << d << "\n";
        }
    }

    return 0;
}