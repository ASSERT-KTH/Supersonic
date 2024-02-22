#include <iostream>
#include <vector>

#define MAX 200010

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> graph[MAX];
vector<ll> treeSize(MAX), heavyChild(MAX), depth(MAX), parent(MAX), otherEnd(MAX), subtreeCost(MAX), nodeCost(MAX), BIT(MAX), chainHead(MAX), posInBase(MAX);
ll n, k, ptr;

ll queryBIT(ll idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += BIT[idx];
    }
    return sum;
}

void updateBIT(ll idx, ll val) {
    for (; idx <= ptr; idx += idx & -idx) {
        BIT[idx] += val;
    }
}

void dfs(ll node, ll par, ll cost) {
    treeSize[node] = 1;
    subtreeCost[node] = cost % k;
    parent[node] = par;
    heavyChild[node] = -1;

    for (auto it : graph[node]) {
        if (it.first != par) {
            depth[it.first] = depth[node] + 1;
            otherEnd[it.first] = it.second;
            dfs(it.first, node, it.second);

            treeSize[node] += treeSize[it.first];

            if (heavyChild[node] == -1 || treeSize[it.first] > treeSize[heavyChild[node]]) {
                heavyChild[node] = it.first;
            }
        }
    }
}

void HLD(ll node, ll par, ll cost) {
    if (chainHead[ptr] == -1) {
        chainHead[ptr] = node;
    }
    nodeCost[node] = cost;
    posInBase[node] = ptr;
    updateBIT(ptr, cost);

    if (heavyChild[node] != -1) {
        HLD(heavyChild[node], node, otherEnd[heavyChild[node]]);
    }

    for (auto it : graph[node]) {
        if (it.first != par && it.first != heavyChild[node]) {
            ptr++;
            HLD(it.first, node, it.second);
        }
    }
}

ll queryUp(ll u, ll v) {
    ll uchain, vchain = posInBase[v], ans = 0;

    while (1) {
        uchain = posInBase[u];

        if (uchain > vchain) {
            swap(u, v);
            swap(uchain, vchain);
        }

        ans += queryBIT(vchain) - queryBIT(uchain - 1);

        if (u == v) {
            break;
        }

        v = parent[chainHead[uchain]];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (ll i = 1, u, v, c; i < n; i++) {
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    dfs(1, 0, 0);
    ptr = 1;
    HLD(1, 0, 0);

    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll u, v;
            cin >> u >> v;
            cout << queryUp(u, v) << "\n";
        } else {
            ll u, v;
            cin >> u >> v;
            updateBIT(posInBase[u], v - nodeCost[u]);
            nodeCost[u] = v;
        }
    }
    return 0;
}