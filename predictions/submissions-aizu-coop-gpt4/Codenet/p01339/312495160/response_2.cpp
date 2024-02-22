#include <iostream>
#include <vector>
#include <cstring>
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL

typedef long long ll;
typedef std::vector<ll> vi;

int graphSize, edgesCount;
std::vector<vi> graph;
std::vector<vi> reverseGraph;
std::vector<int> visited;
std::vector<int> List;
std::vector<int> cycle;
std::vector<int> inCycle;
std::vector<ll> dp;

void dfs(int cur) {
    if (visited[cur]) {
        int from = 0;
        while (List[from] != cur){
            from++;
        }
        for (int i=from; i<List.size(); i++) { 
            cycle.push_back(List[i]); 
        }
        return;
    }
    visited[cur] = 1;
    List.push_back(cur);
    if (graph[cur].size() == 0) {
        cycle.push_back(cur);
        return;
    }
    for (int i=0; i<graph[cur].size(); i++) { 
        dfs(graph[cur][i]); 
    }
}

ll solve(int node) {
    ll &res = dp[node];
    if (res != -1){
        return res;
    }
    visited[node] = 1;
    res = 1;
    for (int i=0; i<reverseGraph[node].size(); i++) { 
        res = res * solve(reverseGraph[node][i]) % MOD; 
    }
    res = (res + 1) % MOD;
    return res;
}

ll compute(int startNode) {
    List.clear();
    cycle.clear();
    dfs(startNode);
    ll result = 1;
    for (int i=0; i<cycle.size(); i++) {
        inCycle[cycle[i]] = 1;
    }
    for (int i=0; i<cycle.size(); i++){
        for (int j=0; j<reverseGraph[cycle[i]].size(); j++) {
            if (inCycle[reverseGraph[cycle[i]][j]]){
                continue;
            }
            result = result * solve(reverseGraph[cycle[i]][j]) % MOD;
        }
    }
    result = (result + 1) % MOD;
    return result;
}
int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    std::cin >> graphSize >> edgesCount;
    graph.resize(graphSize);
    reverseGraph.resize(graphSize);
    visited.resize(graphSize, 0);
    inCycle.resize(graphSize, 0);
    dp.resize(graphSize, -1);
    for (int i=0; i<edgesCount; i++) {
        int s, d;
        std::cin >> s >> d;
        s--;
        d--;
        graph[s].push_back(d);
        reverseGraph[d].push_back(s);
    }
    ll ans = 1;
    for (int i=0; i<graphSize; i++){
        if (!visited[i]){
            ans = ans * compute(i) % MOD;
        }
    }
    std::cout << ans << std::endl;
}