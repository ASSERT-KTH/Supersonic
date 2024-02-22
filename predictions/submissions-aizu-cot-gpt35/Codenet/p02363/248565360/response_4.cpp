#include <iostream>
#include <sstream>
#include <array>

constexpr int MAX = 100000;

struct Edge {
  int s, t, d;
};

std::array<Edge, MAX> edges;
std::stringstream ans;
std::array<int, MAX> d;

int BellmanFord(int startVertex, int vNum, int eNum) {
  d.fill(__INT_MAX__);
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      Edge e = edges[j];
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          ans << "NEGATIVE CYCLE" << std::endl;
          return -1;
        }
      }
    }
    if (!update)
      break;
  }

  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans << " ";
    if (d[i] == __INT_MAX__) {
      ans << "INF";
    } else {
      ans << d[i];
    }
  }

  return 0;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  for (int i = 0; i < eNum; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    edges[i] = {s, t, w};
  }

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans << std::endl;
  }

  std::cout << ans.str();
}