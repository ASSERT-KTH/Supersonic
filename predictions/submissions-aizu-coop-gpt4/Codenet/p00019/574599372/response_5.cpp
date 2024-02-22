#include <cstdio>
#include <iostream>
using namespace std;

long long factorial(int start, int end) {
    if (start > end) 
        return 1;
    if (start == end) 
        return start;
    int mid = (start + end) / 2;
    return factorial(start, mid) * factorial(mid + 1, end);
}

int main() {
    int n;
    cin >> n;
    cout << factorial(2, n) << endl;
    return 0;
}