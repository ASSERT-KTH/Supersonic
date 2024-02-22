#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::vector<double> input(8);
    for (double& val : input) {
      std::cin >> val;
    }

    double k = (input[2] - input[0]) * (input[7] - input[5]) - (input[3] - input[1]) * (input[6] - input[4]);

    if (k == 0)
      std::cout << "2\n";
    else if (k == 0)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }

  return 0;
}