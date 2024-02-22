#include <iostream>
#include <vector>
#include <cstring>

int main() {
  int a = 0, b = 0;
  std::vector<std::pair<int, int>> dimensions;

  while (true) {
    int h, w;
    if (scanf("%d %d", &h, &w) != 2)
      break;
    if (h == 0 && w == 0)
      break;
    dimensions.push_back(std::make_pair(h, w));
    a++;
  }

  while (b < a) {
    int h = dimensions[b].first;
    int w = dimensions[b].second;

    char buffer[101];
    memset(buffer, '#', w);
    buffer[w] = '\n';

    for (int i = 0; i < h; i++) {
      fwrite(buffer, sizeof(char), w + 1, stdout);
    }

    b++;
    putchar('\n');
  }

  return 0;
}