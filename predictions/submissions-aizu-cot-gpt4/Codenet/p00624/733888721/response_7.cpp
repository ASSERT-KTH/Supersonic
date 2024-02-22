#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
#include <array>

const std::array<int, 4> dx = {0, 1, 0, -1};
const std::array<int, 4> dy = {-1, 0, 1, 0};

constexpr int MAX_SIZE = 3;
constexpr int DIRECTIONS = 4;

std::array<std::array<int, MAX_SIZE>, MAX_SIZE> bfscost;
std::array<char, MAX_SIZE> csize, wsize, wx, wy, cx, cy;
std::array<std::array<char, MAX_SIZE>, MAX_SIZE> field;
std::array<std::array<std::array<std::array<std::array<std::array<std::array<std::array<char, MAX_SIZE>, MAX_SIZE>, MAX_SIZE>, MAX_SIZE>, MAX_SIZE>, MAX_SIZE>, MAX_SIZE> DP;

struct State {
  // ...
};

// ...

int main() {
  // ...

  for (auto i = 0; i < H; ++i) {
    scanf("%s", field[i].data());
    for (auto j = 0; j < W; ++j) {
      // ...
    }
  }

  // ...
}