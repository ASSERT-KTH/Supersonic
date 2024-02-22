template <typename Monoid, typename Operand>
class link_cut_tree {
  // ...
public:
  link_cut_tree(uint32 size) : tree(size) {
    v.resize(size);
  }
  link_cut_tree(std::vector<Monoid> &&a) : tree(std::move(a)) {
    for (uint32 i = 0; i < a.size(); ++i) {
      tree[i].value = tree[i].sum = a[i];
    }
    v.resize(a.size());
  }
  // ...
  void push() {
    if (b & 2) {
      if (left != right) {
        node_t *temp = left;
        left = right;
        right = temp;
      }
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
  // ...
  // remove the scan method
};