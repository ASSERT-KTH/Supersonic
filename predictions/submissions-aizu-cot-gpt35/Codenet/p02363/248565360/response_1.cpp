#include <iostream>
#include <limits>
#include <string>
#include <vector>

const int MAX_VERTICES = 100000;

class Edge {
public:
  Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}

  int getStart() const { return start; }
  int getEnd() const { return end; }
  int getWeight() const { return weight; }

private:
  int start;
  int end;
  int weight;
};

std::string BellmanFord(int startVertex, int vNum, int eNum, const std::vector<Edge>& edges) {
  std::vector<int> d(vNum, std::numeric_limits<int>::max());
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;

    for (const auto& edge : edges) {
      if (d[edge.getStart()] != std::numeric_limits<int>::max() &&
          d[edge.getEnd()] > d[edge.getStart()] + edge.getWeight()) {
        d[edge.getEnd()] = d[edge.getStart()] + edge.getWeight();
        update = true;

        if (i == vNum - 1) {
          return "NEGATIVE CYCLE";
        }
      }
    }

    if (!update)
      break;
  }

  std::string ans;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans.append(" ");

    if (d[i] == std::numeric_limits<int>::max()) {
      ans.append("INF");
    } else {
      ans.append(std::to_string(d[i]));
    }
  }

  return ans;
}

int main() {
  int vNum, eNum;
  std::cin >> vNum >> eNum;

  std::vector<Edge> edges;
  edges.reserve(eNum);

  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    std::cin >> s >> t >> w;
    edges.emplace_back(s, t, w);
  }

  std::string ans;
  for (int i = 0; i < vNum; ++i) {
    std::string result = BellmanFord(i, vNum, eNum, edges);
    if (result == "NEGATIVE CYCLE") {
      return 0;
    }
    ans.append(result).append("\n");
  }

  std::cout << ans;

  return 0;
}