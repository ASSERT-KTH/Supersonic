#include <iostream>
using namespace std;

int main() {
    int n, m;
    int x, y, a[100][100], b[100];
    int c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            a[i][j] = x;
        }
    }
    for (int j = 0; j < m; j++) {
        cin >> y;
        b[j] = y;
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < m; j++) {
            temp += a[i][j] * b[j];
        }
        cout << temp << endl;
    }
    return 0;
}