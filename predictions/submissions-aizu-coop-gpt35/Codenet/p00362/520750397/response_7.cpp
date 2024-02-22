#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 200000;

struct Node {
    L parent;
    vector<L> children;
    L weight;
};

Node tree[MAX_NODES];
L P[MAX_NODES], E[MAX_NODES], Z[MAX_NODES], H[MAX_NODES], C[MAX_NODES], A[MAX_NODES], O[MAX_NODES], X[MAX_NODES], B[MAX_NODES];
L k, n, a, b, c;
char s;

L sumValues(L node) {
    L sum = A[node];
    for (L child : tree[node].children) {
        sum += sumValues(child);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        tree[a].children.push_back(b);
        tree[a].weight = c;
        tree[b].children.push_back(a);
        tree[b].weight = c;
    }
    
    // Preprocess tree structure
    L a = 0, b = 0;
    vector<L> stack;
    stack.push_back(0);
    
    while (!stack.empty()) {
        L node = stack.back();
        
        if (!tree[node].children.empty() && a != tree[node].children[0]) {
            b = a;
            a = tree[node].children[0];
        } else {
            stack.pop_back();
            tree[node].weight = ++b;
            for (L child : tree[node].children) {
                stack.push_back(child);
            }
        }
    }
    
    while (cin >> s >> a >> b) {
        if (s & 2) {
            cout << sumValues(a) << endl;
        } else {
            A[a] += b;
        }
    }
    
    return 0;
}