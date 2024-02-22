#include <iostream>
#include <stack>
using namespace std;

int n, b[2][100100], f[2][100100];
int maxWeight[100100];
int numPaths[100100];

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      maxWeight[i] = 0;
      numPaths[i] = 0;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (maxWeight[i] == 0 && numPaths[i] == 0) {
        stack<int> nodeStack;
        nodeStack.push(i);

        while (!nodeStack.empty()) {
          int node = nodeStack.top();
          nodeStack.pop();

          if (maxWeight[node] != 0 && numPaths[node] != 0) {
            ans = (ans * numPaths[node]) % 10007;
            continue;
          }

          maxWeight[node] = f[0][node];
          numPaths[node] = 1;

          for (int j = 0; j < 2; j++) {
            int nextNode = b[j][node];
            if (nextNode == i) {
              ans = (ans * numPaths[node]) % 10007;
            } else if (maxWeight[nextNode] < f[j][node]) {
              maxWeight[nextNode] = f[j][node];
              numPaths[nextNode] = numPaths[node];
              nodeStack.push(nextNode);
            } else if (maxWeight[nextNode] == f[j][node]) {
              numPaths[nextNode] = (numPaths[nextNode] + numPaths[node]) % 10007;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}