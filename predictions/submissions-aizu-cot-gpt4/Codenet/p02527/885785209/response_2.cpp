#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
int a[1000010];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  srand(time(0));
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  for (int i = 0; i < n; i++)
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
}