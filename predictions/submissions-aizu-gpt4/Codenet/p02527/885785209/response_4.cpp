#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void quicksort(T *begin, T *end) {
  if (begin != end) {
    T *pivot = partition(begin, end, [end](T val) { return val < *(end - 1); });
    quicksort(begin, pivot);
    quicksort(pivot + 1, end);
  }
}

int main() {
  srand(time(0));
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  quicksort(a.data(), a.data() + n);
  for (const int &i : a)
    cout << i << ' ';
  cout << '\n';
}