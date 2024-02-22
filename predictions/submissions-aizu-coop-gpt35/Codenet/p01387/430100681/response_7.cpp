template <class Key> struct RandomizedBinarySearchTree {
  // ...
  vector<Node*> pool;
  int ptr;
  RandomizedBinarySearchTree(int sz) : pool(sz), ptr(0) {}
  inline Node* alloc(const Key& key) { return new Node(key); }
  // ...
};