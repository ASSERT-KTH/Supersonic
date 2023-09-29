#include <iostream>
#include <algorithm>

constexpr int MAX_SIZE = 1000000;

int main(void) {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  delete[] a;
  return 0;
}