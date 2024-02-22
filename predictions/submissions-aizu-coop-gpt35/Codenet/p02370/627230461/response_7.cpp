#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
  Graph(int numVertices) : adjList(numVertices), inDegree(numVertices, 0) {}

  void addEdge(int source, int destination) {
    adjList[source].push_back(destination);
    inDegree[destination]++;
  }

  const list<int>& getAdjacentVertices(int vertex) const {
    return adjList[vertex];
  }

  int getInDegree(int vertex) const {
    return inDegree[vertex];
  }

private:
  vector<list<int>> adjList;
  vector<int> inDegree;
};

int main() {
  int V, E;
  cin >> V >> E;

  Graph graph(V);

  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    graph.addEdge(s, t);
  }

  vector<int> ans;
  for (int i = 0; i < V; i++) {
    if (graph.getInDegree(i) == 0) {
      ans.push_back(i);
    }
  }

  for (int i : ans) {
    for (int j : graph.getAdjacentVertices(i)) {
      graph.addEdge(i, j);
      if (--graph.getInDegree(j) == 0) {
        ans.push_back(j);
      }
    }
  }

  for (int i : ans) {
    cout << i << endl;
  }

  return 0;
}