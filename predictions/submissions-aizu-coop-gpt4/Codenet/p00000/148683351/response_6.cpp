#include <iostream>
#include <sstream>
using namespace std;

int main() {
  // Compute all multiplication results in advance
  int results[10][10];
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      results[i][j] = i * j;
    }
  }

  // Collect all output in a string
  ostringstream output;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      output << i << "x" << j << "=" << results[i][j] << endl;
    }
  }

  // Print the output to the console once
  cout << output.str();

  return 0;
}