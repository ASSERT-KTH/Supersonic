#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000001
using namespace std;

long long count = 0;
vector<int> mergeSort(vector<int>& a) {
    int n = a.size();
    if(n > 1) {
        vector<int> b(a.begin(), a.begin()+n/2);
        vector<int> c(a.begin()+n/2, a.end());
        b = mergeSort(b);
        c = mergeSort(c);
        a.clear();
        merge(b.begin(), b.end(), c.begin(), c.end(), back_inserter(a));
        count += b.size() * c.size();
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    a = mergeSort(a);
    for(int i=0; i<n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << count << "\n";
    return 0;
}