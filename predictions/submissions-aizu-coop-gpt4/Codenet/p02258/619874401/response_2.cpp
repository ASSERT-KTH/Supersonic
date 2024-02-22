#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static const int MAX = 200000;

int main() {
    int R[MAX], n;
    cin >> n;
    cin.ignore();  // ignore newline character

    string line;
    getline(cin, line);
    stringstream ss(line);
    for (int i = 0; i < n; i++)
        ss >> R[i];

    int maxv = R[1] - R[0];
    int minv = R[0];
    for (int i = 1; i < n; i++) {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;

    return 0;
}