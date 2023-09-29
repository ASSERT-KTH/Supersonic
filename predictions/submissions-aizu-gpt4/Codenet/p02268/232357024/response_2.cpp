#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> S(n);
    for(int& v : S) {
        cin >> v;
    }

    int cnt = 0;
    int q;
    cin >> q;

    while(q--) {
        int T;
        cin >> T;
        cnt += binary_search(S.begin(), S.end(), T);
    }

    cout << cnt << '\n';
    return 0;
}