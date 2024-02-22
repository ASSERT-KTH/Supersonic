#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int Q, N, count, max_prod, S;
  bool FLG;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    unordered_set<int> visited_numbers;
    count = 0;
    scanf("%d", &N);
    visited_numbers.insert(N);
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      string num_str = to_string(N);
      int len = num_str.length();
      int first_num = stoi(num_str.substr(0, len/2));
      int second_num = stoi(num_str.substr(len/2));
      max_prod = first_num * second_num;
      N = (max_prod > N) ? max_prod : N;
      if (visited_numbers.find(N) != visited_numbers.end()) {
        FLG = true;
        break;
      } else {
        visited_numbers.insert(N);
        count++;
      }
    }
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}