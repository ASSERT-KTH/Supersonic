#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int c[21];
    int mini[50001];
    fill_n(mini, n+1, INF); // Filling mini array with INF
    mini[0] = 0;

    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    // Removed sort operation here
  
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n - c[i]; j++) {
            // Using std::min function directly during assignment
            mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
        }
    }

    cout << mini[n] << '\n';
    return 0;
}