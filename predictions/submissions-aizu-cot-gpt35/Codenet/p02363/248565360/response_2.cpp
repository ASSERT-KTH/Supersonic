#include <iostream>
#include <vector>

struct edge {
  int s, t, d;
};

void BellmanFord(int startVertex, int vNum, int eNum, std::vector<edge>& edges) {
  int INF = 1e9;
  std::vector<int> d(vNum, INF);
  std::string ans;

  d[startVertex] = 0;
  for (int i = 0; i <= vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != INF && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum) {
          std::cout << "NEGATIVE CYCLE" << std::endl;
          return;
        }
      }
    }
    if (!update)
      break;
  }

  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans.append(" ");
    if (d[i] == INF) {
      ans.append("INF");
    } else {
      ans.append(std::to_string(d[i]));
    }
  }

  std::cout << ans;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  std::vector<edge> edges;
  for (int i = 0; i < eNum; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }

  for (int i = 0; i < vNum; ++i) {
    BellmanFord(i, vNum, eNum, edges);
    std::cout << std::endl;
  }
}