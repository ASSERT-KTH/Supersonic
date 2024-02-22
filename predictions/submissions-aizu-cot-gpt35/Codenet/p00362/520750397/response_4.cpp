#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_NODES = 200000;
vector<int> parent(MAX_NODES, 0);
vector<int> depth(MAX_NODES, 0);
vector<int> children[MAX_NODES];
vector<int> values(MAX_NODES, 0);
vector<int> subtreeSum(MAX_NODES, 0);
int k, n;

int calculateSubtreeSum(int node) {
    int sum = values[node];
    for (int child : children[node]) {
        sum += calculateSubtreeSum(child);
    }
    subtreeSum[node] = sum;
    return sum;
}

int calculatePathSum(int node) {
    int sum = 0;
    while (node != 0) {
        sum += subtreeSum[node];
        node = parent[node];
    }
    return sum;
}

int calculateDifference(int node1, int node2) {
    int sum1 = calculatePathSum(node1);
    int sum2 = calculatePathSum(node2);
    return abs(sum1 - sum2);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        parent[b] = a;
        depth[b] = depth[a] + 1;
        children[a].push_back(b);
        values[a] = c;
    }

    calculateSubtreeSum(0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char s;
        int a, b;
        cin >> s >> a >> b;
        if (s & 2) {
            int difference = calculateDifference(a, b);
            cout << difference << endl;
        } else {
            values[a] += b;
        }
    }

    return 0;
}