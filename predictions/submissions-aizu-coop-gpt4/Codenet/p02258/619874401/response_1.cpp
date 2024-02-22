#include <iostream>
using namespace std;

static const int MAX = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int R[MAX], n;
    cin >> n;
  
    for (int i = 0; i < n; i++)
        cin >> R[i];
  
    int maxv = R[1] - R[0];
    int minv = R[0];
  
    for (int i = 1; i < n; i++) {
        int diff = R[i] - minv;
        if (diff > maxv)
            maxv = diff;
        if (R[i] < minv)
            minv = R[i];
    }
  
    cout << maxv << endl;
    return 0;
}