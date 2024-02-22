...
void query(int a, int b, const function<void(int, int, int)> &f) {
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  tie(TreeIdxA, TreeDepthA) = Information(a);
  tie(TreeIdxB, TreeDepthB) = Information(b);
  int depthA = Centroids[TreeIdxA].Deep;
  int depthB = Centroids[TreeIdxB].Deep;
  while (TreeIdxA != TreeIdxB) {
    if (depthA > depthB) {
      f(TreeIdxA, 0, TreeDepthA + 1);
      tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      depthA = Centroids[TreeIdxA].Deep;
    } else {
      f(TreeIdxB, 0, TreeDepthB + 1);
      tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      depthB = Centroids[TreeIdxB].Deep;
    }
  }
  ...
}
...
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ...
}
...
Node *rebuild(Node *r) {
  // some function that modifies the existing tree in place
  return modifyTreeInPlace(RBST::dump(r));
}
...
vector<Key> dump(Node *r) {
  vector<Key> v;
  v.reserve((size_t)count(r));
  auto it = begin(v);
  dump(r, it);
  return v;
}
...
inline pair<int, int> Information(int idx) {
  if (storedInformation.find(idx) == storedInformation.end()) { 
    storedInformation[idx] = make_pair(TreeIndex[idx], TreeDepth[idx]);
  }
  return storedInformation[idx];
}
...