#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
}