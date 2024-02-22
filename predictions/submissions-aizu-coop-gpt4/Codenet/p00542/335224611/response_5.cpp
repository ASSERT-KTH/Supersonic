#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int arr[6];
  for(int i=0; i<6; i++)
    cin >> arr[i];
  
  int min_value = min(min(arr[0], arr[1]), min(arr[2], arr[3]));
  int max_value = max(arr[4], arr[5]);

  int ans = arr[0] + arr[1] + arr[2] + arr[3] - min_value + max_value;
  cout << ans << endl;

  return 0;
}