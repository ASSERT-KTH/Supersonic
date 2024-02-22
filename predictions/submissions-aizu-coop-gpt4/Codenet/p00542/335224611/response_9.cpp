#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int numbers[6];
  
  for(int i = 0; i < 6; i++) {
    cin >> numbers[i];
  }

  int min_val = min({numbers[0], numbers[1], numbers[2], numbers[3]});
  int max_val = max(numbers[4], numbers[5]);
  
  int sum = numbers[0] + numbers[1] + numbers[2] + numbers[3] - min_val + max_val;

  cout << sum << "\n";

  return 0;
}