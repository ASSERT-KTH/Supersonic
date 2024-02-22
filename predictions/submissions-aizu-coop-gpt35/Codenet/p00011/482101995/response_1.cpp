#include <iostream>
#include <vector>
using namespace std;

int main() {
  int w;
  cin >> w;
  int n;
  cin >> n;

  // Initialize the StartingPoint vector with the desired values
  vector<int> StartingPoint(w, 0);
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    int left, right;
    char Dummy;
    cin >> left >> Dummy >> right;

    // Assign values directly to the StartingPoint vector
    StartingPoint[left - 1] = right;
    StartingPoint[right - 1] = left;
  }

  // Print the entire StartingPoint vector using a single cout statement
  for (int i = 0; i < w; i++) {
    cout << StartingPoint[i] << endl;
  }

  return 0;
}