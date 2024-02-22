#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    long long T[7 << 15] = {};
    long long P[7 << 15] = {};
    long long E[7 << 15] = {};
    long long Z[7 << 15] = {};
    long long H[7 << 15] = {};
    long long C[7 << 15] = {};
    long long A[7 << 15] = {};
    long long O[7 << 15] = {};
    long long X[7 << 15] = {};
    long long B[7 << 15] = {};
    long long k, n, a, b, c;
    char s[7 << 15] = {};
    map<long long, long long> T_map;

    long long M(long long f) { 
        if (f) {
            return B[f] + M(f ^ f & -f);
        } else {
            return 0;
        }
    }

    // Remaining code goes here

    return 0;
}