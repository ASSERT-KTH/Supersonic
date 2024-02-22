vector<bool> vis(100000000 / 8);
inline bool ck(int x) {
  return vis[x >> 3] & (1 << (x & 7));
}
inline void sb(int x) {
  vis[x >> 3] |= (1 << (x & 7));
}
inline void cb(int x) {
  vis[x >> 3] &= ~(1 << (x & 7));
}