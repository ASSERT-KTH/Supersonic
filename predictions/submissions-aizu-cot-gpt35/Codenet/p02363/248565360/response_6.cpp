#include <iostream>
#include <vector>
#include <limits>

struct edge {
  int s, t, d;
};

std::vector<edge> edges;
std::string ans;
std::vector<int> d;

int BellmanFord(int startVertex, int vNum, int eNum) {
  d.assign(vNum, std::numeric_limits<int>::max());
  d[startVertex] = 0;

  for (size_t i = 0; i < vNum; ++i) {
    bool update = false;

    for (size_t j = 0; j < eNum; ++j) {
      edge e = edges[j];

      if (d[e.s] != std::numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;

        if (i == vNum - 1) {
          std::cout << "NEGATIVE CYCLE" << std::endl;
          return -1;
        }
      }
    }

    if (!update)
      break;
  }

  for (size_t i = 0; i < vNum; ++i) {
    if (i != 0)
      ans += " ";

    if (d[i] == std::numeric_limits<int>::max()) {
      ans += "INF";
    } else {
      ans += std::to_string(d[i]);
    }
  }

  return 0;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  int s, t, w;
  for (size_t i = 0; i < eNum; ++i) {
    std::cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }

  for (size_t i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }

    ans += "\n";
  }

  std::cout << ans;

  return 0;
}