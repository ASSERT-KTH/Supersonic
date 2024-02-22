#include <iostream>
#include <cstdio>
#include <cmath>

#define MAX 999999

using namespace std;

int primes[MAX + 1];

int main() {
    primes[0] = primes[1] = -1;
    
    for (int i = 2; i <= sqrt(MAX); ++i) {
        if (primes[i] != -1) {
            for (int j = i * i; j <= MAX; j += i) {
                primes[j] = -1;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (primes[i] != -1) {
            count++;
        }
        primes[i] = count;
    }
    
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", primes[n]);
    }
    
    return 0;
}