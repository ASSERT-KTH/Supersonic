#include <iostream>
#include <math.h>
using namespace std;
#define int long long

int isPrime[300000+1];

void sieve(){
    for(int i=0;i<=300000;i++)
        isPrime[i] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2;i*i<=300000;i++){
        if(isPrime[i] == 1){
            for(int j=i*i;j<=300000;j+=i)
                isPrime[j] = 0;
        }
    }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  sieve();
  int primes[300000+1], k = 0;
  for(int i=2; i<=300000; i++){
    if((i%7 == 1 || i%7 == 6) && isPrime[i])
      primes[k++] = i;
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    cout << n << ':';
    for(int i=0; i<k; i++){
      if(n % primes[i] == 0)
        cout << " " << primes[i];
    }
    cout << endl;
  }
}