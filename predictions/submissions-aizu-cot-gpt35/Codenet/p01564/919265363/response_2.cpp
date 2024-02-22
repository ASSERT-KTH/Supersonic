#include <algorithm>
#include <iostream>
#include <vector>

struct douse {
    int all, max_suffix, sum, siz;

    douse() : all(0), max_suffix(0), sum(0), siz(0) {}
    douse(int a, int s, int si) : all(a), max_suffix(a), sum(s), siz(si) {}

    douse operator+(const douse& other) {
        douse ret;
        ret.all = std::max(std::max(all, other.all), max_suffix + other.max_suffix);
        ret.max_suffix = std::max(other.max_suffix, sum + other.max_suffix);
        ret.sum = sum + other.sum;
        ret.siz = siz + other.siz;
        return ret;
    }

    douse operator*(int data) {
        douse ret;
        ret.all = ret.max_suffix = ret.sum = data * siz;
        ret.siz = siz;
        return ret;
    }
};

template <typename Monoid, typename Operand>
class link_cut_tree {
    struct node_t {
        node_t* left;
        node_t* right;
        node_t* per;
        Monoid value;
        Monoid sum;
        Operand lazy;
        uint8_t b;

        node_t()
            : left(nullptr), right(nullptr), per(nullptr), value(Monoid()), sum(Monoid()), b(0) {}

        Monoid reflect() {
            if (b & 1) {
                if (b & 2)
                    return ~(sum * lazy);
                return sum * lazy;
            }
            if (b & 2)
                return ~sum;
            return sum;
        }

        void assign(Operand& data) {
            if (b & 1)
                lazy = lazy * data;
            else {
                lazy = data;
                b |= 1;
            }
        }

        void push() {
            if (b & 2) {
                std::swap(left, right);
                left->b ^= 2;
                right->b ^= 2;
                value = ~value;
            }
            if (b & 1) {
                value = value * lazy;
                left->assign(lazy);
                right->assign(lazy);
            }
            b &= ~3;
        }

        void propagate() {
            if (per)
                per->propagate();
            push();
        }

        void splay() {
            node_t* x = this;
            node_t* pp;
            while (!x->isroot()) {
                if (per->isroot()) {
                    if (per->left == this) {
                        per->left = right;
                        per->recalc();
                        right = per;
                    } else {
                        per->right = left;
                        per->recalc();
                        left = per;
                    }
                    x = per;
                    per = per->per;
                    recalc();
                    break;
                }
                x = per->per;
                pp = x->per;
                if (per->left == this) {
                    if (x->left == per) {
                        x->left = per->right;
                        per->left = right;
                        per->right = x;
                        right = per;
                    } else {
                        x->right = left;
                        per->left = right;
                        right = per;
                        left = x;
                    }
                } else {
                    if (x->right == per) {
                        x->right = per->left;
                        per->right = left;
                        per->left = x;
                        left = per;
                    } else {
                        x->left = right;
                        per->right = left;
                        left = per;
                        right = x;
                    }
                }
                x->recalc();
                per->recalc();
                recalc();
                per = pp;
                if (pp) {
                    if (pp->left == x) {
                        pp->left = this;
                    } else if (pp->right == x) {
                        pp->right = this;
                    }
                }
            }
            x->b |= 4;
        }

        void expose(node_t* prev) {
            splay();
            right->b &= ~4;
            right = prev;
            recalc();
            if (per)
                per->expose(this);
            else {
                b &= ~4;
            }
        }

        void recalc() {
            sum = value;
            if (left != nullptr) {
                sum = left->reflect() + sum;
                left->per = this;
            }
            if (right != nullptr) {
                sum = sum + right->reflect();
                right->per = this;
            }
        }

        bool isroot() { return !(b & 4); }
    };

    std::vector<node_t> tree;

public:
    link_cut_tree(uint32_t size) : tree(size) {}

    void link(uint32_t child, uint32_t per) {
        evert(child);
        tree[child].per = &tree[per];
    }

    void cut(uint32_t child) {
        node_t* n = &tree[child];
        expose(n);
        n->left->per = nullptr;
        n->left = nullptr;
        n->sum = n->value;
    }

    void update(uint32_t u, uint32_t v, int data) {
        evert(u);
        expose(&tree[v]);
        tree[v].lazy = data;
        tree[v].b |= 1;
    }

    douse path(uint32_t u, uint32_t v) {
        evert(u);
        expose(&tree[v]);
        return tree[v].sum;
    }

    void evert(uint32_t v) {
        expose(&tree[v]);
        tree[v].b ^= 2;
    }

    void expose(node_t* n) {
        n->propagate();
        n->expose(nullptr);
        n->splay();
        n->b &= ~4;
        n->recalc();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    uint32_t n, q;
    scanf("%u %u", &n, &q);

    std::vector<douse> a(n);