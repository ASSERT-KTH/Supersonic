#include <iostream>
#include <string>
#include <vector>

class Edge {
public:
  int s, t, d;
};

std::vector<Edge> edges;
std::string ans;

int BellmanFord(int startVertex, int vNum, int eNum) {
  int d[vNum];
  for (int i = 0; i < vNum; ++i) {
    d[i] = INT_MAX;
  }

  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (const auto& e : edges) {
      if (d[e.s] != INT_MAX && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          std::cout << "NEGATIVE CYCLE" << std::endl;
          return -1;
        }
      }
    }
    if (!update) {
      break;
    }
  }

  for (int i = 0; i < vNum; ++i) {
    if (i > 0) {
      ans.push_back(' ');
    }
    if (d[i] == INT_MAX) {
      ans.append("INF");
    } else {
      ans.append(std::to_string(d[i]));
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
    edges.push_back({s, t, w});
  }

  for (const auto& edge : edges) {
    if (BellmanFord(edge.s, vNum, eNum) == -1) {
      return 0;
    }
    ans.push_back('\n');
  }

  std::cout << ans;
}