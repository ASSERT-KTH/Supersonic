#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> S(N);
    for (int& s : S)
        cin >> s;

    int cnt = 0;
    sort(S.begin(), S.end(), [&cnt](int a, int b) {
        cnt++;
        return a < b;
    });

    for (int i = 0; i < N; ++i) {
        if (i > 0)
            cout << " ";
        cout << S[i];
    }
    cout << "\n" << cnt << "\n";

    return 0;
}