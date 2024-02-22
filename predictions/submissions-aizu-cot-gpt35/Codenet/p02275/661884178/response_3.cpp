#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int min = 2000000, t;
    vector<int> A(10001, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        min = std::min(min, t);
        A[t]++;
    }
    
    A[min]--;
    cout << min;
    
    for (int i = min; i < 10001; i++) {
        fill_n(ostream_iterator<int>(cout, " "), A[i], i);
    }
    
    cout << endl;
    
    return 0;
}