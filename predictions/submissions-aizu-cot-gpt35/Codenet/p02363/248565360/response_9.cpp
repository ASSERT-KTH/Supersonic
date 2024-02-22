#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

constexpr int MAX = 100000;

struct edge {
  int s, t, d;
};

std::vector<edge> edges;
std::string ans;
int d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  std::fill(d, d + MAX, __INT_MAX__);
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;

    for (const edge& e : edges) {
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
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

  std::stringstream ss;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ss << " ";

    if (d[i] == __INT_MAX__) {
      ss << "INF";
    } else {
      ss << d[i];
    }
  }

  ans = ss.str();
  return 0;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  int s, t, w;
  edges.reserve(eNum);

  for (int i = 0; i < eNum; ++i) {
    std::cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }

    ans.append("\n");
  }

  std::cout << ans;
}