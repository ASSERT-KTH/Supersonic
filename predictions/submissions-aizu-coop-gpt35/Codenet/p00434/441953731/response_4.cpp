#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MAX_NUM = 30;
  const int NUM_INPUTS = 28;

  vector<bool> data(MAX_NUM, false);
  int n;

  for (int i = 0; i < NUM_INPUTS; i++) {
    scanf("%d", &n);
    data[n - 1] = true;
  }

  vector<int> missingNumbers;
  for (int i = 0; i < MAX_NUM; i++) {
    if (!data[i]) {
      missingNumbers.push_back(i + 1);
    }
  }

  for (int missingNumber : missingNumbers) {
    cout << missingNumber << endl;
  }

  return 0;
}