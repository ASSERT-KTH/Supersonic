// Replace
vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
// With
bool** field = new bool*[H + 2];
for (int i = 0; i < H + 2; ++i) {
  field[i] = new bool[W + 2];
  memset(field[i], false, sizeof(bool) * (W + 2));
}