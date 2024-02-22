#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define INF 1e9

std::vector<int> specialNodes;
std::map<std::pair<int, int>, int> specialDistances;
int distances[1000][1000];
bool isSpecial[1000];

void floydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        distances[i][j] = std::min(distances[i][j], distances[i][k] + distances[k][j]);
      }
    }
  }
}

void updateSpecialDistances(int n, int m) {
  for (int i = 0; i < specialNodes.size(); i++) {
    for (int j = i + 1; j < specialNodes.size(); j++) {
      int a = specialNodes[i], b = specialNodes[j];
      if (distances[a][b] <= m) {
        specialDistances[{a, b}] = distances[a][b];
        specialDistances[{b, a}] = distances[b][a];
      }
    }
  }
}

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (std::cin >> n >> m >> l >> k >> a >> h, n) {
    specialNodes.clear();
    specialDistances.clear();
    std::fill(isSpecial, isSpecial + n, false);
    for (int i = 0; i < n; i++) {
      std::fill(distances[i], distances[i] + n, INF);
      distances[i][i] = 0;
    }

    specialNodes.push_back(a);
    specialNodes.push_back(h);
    isSpecial[a] = true;
    isSpecial[h] = true;

    for (int i = 0; i < l; i++) {
      std::cin >> t1;
      specialNodes.push_back(t1);
      isSpecial[t1] = true;
    }

    for (int i = 0; i < k; i++) {
      std::cin >> t1 >> t2 >> t3;
      distances[t1][t2] = t3;
      distances[t2][t1] = t3;
    }

    floydWarshall(n);
    updateSpecialDistances(n, m);

    int minDistance = specialDistances[{a, h}];
    if (minDistance >= INF)
      std::cout << "Help!" << std::endl;
    else if (minDistance < m)
      std::cout << minDistance << std::endl;
    else
      std::cout << minDistance * 2 - m << std::endl;
  }
}