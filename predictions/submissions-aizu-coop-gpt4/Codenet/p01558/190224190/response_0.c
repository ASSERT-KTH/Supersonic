#include <bits/stdc++.h>
using namespace std;

// Define priority_queue (heap)
priority_queue<long long, vector<long long>, greater<long long>> pq;

// Replace hin() function
void hin(long long a) {
    pq.push(a);
}

// Replace hout() function
int hout() {
    int rt = pq.top();
    pq.pop();
    return rt;
}

// ...

// Main function
int main() {
    // ...

    // Compute getlr(l, r, 0) once and store in a variable
    long long getlr_val = getlr(l, r, 0);
    h[R] = getlr_val;
    hin(getlr_val);

    // ... 

    return 0;
}