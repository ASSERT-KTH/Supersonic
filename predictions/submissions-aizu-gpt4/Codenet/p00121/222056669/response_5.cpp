#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char puzzle[8];
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
int state;
int zeroAt;
int steps;
int dx[4] = {-1, 1, -4, 4};
bool visited[87654322];

struct node {
    int state;
    int zeroAt;
    int steps;
};

void bfs() {
    memset(visited, false, sizeof(visited));
    queue<node> q;
    node start = {state, zeroAt, steps};
    q.push(start);
    visited[state] = true;
    while(!q.empty()) {
        node current = q.front(); q.pop();
        if(current.state == 1234567) {
            printf("%d\n", current.steps);
            return;
        }
        for(int i = 0; i < 4; ++i) {
            int nz = current.zeroAt + dx[i];
            if(nz < 0 || nz > 7 || (current.zeroAt == 3 && nz == 4) || (current.zeroAt == 4 && nz == 3))
                continue;
            int a = current.state / ddd[current.zeroAt] % 10;
            int b = current.state / ddd[nz] % 10;
            int ns = current.state + (b - a) * ddd[current.zeroAt] + (a - b) * ddd[nz];
            if(!visited[ns]) {
                visited[ns] = true;
                q.push({ns, nz, current.steps + 1});
            }
        }
    }
    printf("-1\n");
}

int main() {
    while(scanf("%s", puzzle) != EOF) {
        char* zero = strchr(puzzle, '0');
        zeroAt = zero - puzzle;
        state = 0;
        for(int i = 0; i < 8; ++i) {
            if(puzzle[i] == '0') continue;
            state += ddd[i] * (puzzle[i] - '0');
        }
        bfs();
    }
    return 0;
}