#include <iostream>
#include <cstring>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;

  std::memset(inact, 0, sizeof(inact));
  std::memset(act, 0, sizeof(act));
  std::memset(ans, 0, sizeof(ans));

  std::cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      std::cin >> inact[i][j];
    }
  }
  for (int i = 0; i < col; i++) {
    std::cin >> act[i];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }
  for (int i = 0; i < row; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}