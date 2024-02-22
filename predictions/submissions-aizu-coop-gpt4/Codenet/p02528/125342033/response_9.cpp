#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n, A[1000001];
    cin >> n;
  
    for (int i = 0; i < n; i++)
        cin >> A[i];
  
    sort(A, A + n);
  
    cout << A[0];
    for (int i = 1; i < n; i++)
        cout << " " << A[i];
    cout << "\n";
  
    return 0;
}