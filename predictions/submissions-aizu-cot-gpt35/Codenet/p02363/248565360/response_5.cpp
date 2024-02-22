#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

#define MAX 100000

struct edge {
  int s, t, d;
};

std::vector<edge> edges;
std::string ans;

int d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  std::fill(d, d + MAX, INT_MAX);
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != INT_MAX && d[e.t] > d[e.s] + e.d) {
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
    if (d[i] == INT_MAX) {
      ss << "INF";
    } else {
      ss << d[i];
    }
  }
  ans += ss.str();
  return 0;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  edges.reserve(eNum); // Pre-allocate the required space for the edges vector

  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    std::cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans += "\n";
  }

  std::cout << ans;

  return 0;
}