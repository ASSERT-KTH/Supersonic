#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node {
  int key, prior, cnt;
  Node *l, *r;
  Node() {}
  Node(int key) : key(key), prior((rand() << 16) ^ rand()), cnt(1), l(nullptr), r(nullptr) {}
};

typedef Node* pNode;

int cnt(pNode t) {
  return t ? t->cnt : 0;
}

void update(pNode t) {
  if (t) {
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
  }
}

void split(pNode t, pNode &l, pNode &r, int key) {
  if (!t) {
    l = r = nullptr;
  } else if (key <= t->key) {
    split(t->l, l, t->l, key), r = t;
  } else {
    split(t->r, t->r, r, key), l = t;
  }
  update(t);
}

void merge(pNode &t, pNode l, pNode r) {
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->prior > r->prior) {
    merge(l->r, l->r, r), t = l;
  } else {
    merge(r->l, l, r->l), t = r;
  }
  update(t);
}

void insert(pNode &t, pNode new_node) {
  if (!t) {
    t = new_node;
  } else if (new_node->prior > t->prior) {
    split(t, new_node->l, new_node->r, new_node->key);
    t = new_node;
  } else {
    insert(new_node->key <= t->key ? t->l : t->r, new_node);
  }
  update(t);
}

void erase(pNode &t, int key) {
  if (t->key == key) {
    pNode old_t = t;
    merge(t, t->l, t->r);
    delete old_t;
  } else {
    erase(key <= t->key ? t->l : t->r, key);
  }
  update(t);
}

bool find(pNode t, int key) {
  if (!t) {
    return false;
  }
  if (t->key == key) {
    return true;
  }
  return find(key <= t->key ? t->l : t->r, key);
}

int main() {
  srand(time(0));
  pNode tree = nullptr;
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    insert(tree, new Node(a));
  }
  while (q--) {
    int type, x, y;
    scanf("%d %d %d", &type, &x, &y);
    if (type == 0) {
      erase(tree, x);
      insert(tree, new Node(y));
    } else if (type == 1) {
      printf("%d\n", find(tree, x));
    }
  }
  return 0;
}