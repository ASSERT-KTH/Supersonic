#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 2000000000;
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    int c[21];
    int mini[50001] = {0};
    for (int i = 1; i <= m; i++) {
        scanf("%d",&c[i]);
    }
    for (int i = 1; i <= n; i++)
        mini[i] = INF;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n - c[i]; j++) {
            if (mini[j] + 1 < mini[j + c[i]])
                mini[j + c[i]] = mini[j] + 1;
        }
    }
    printf("%d\n",mini[n]);
    return 0;
}