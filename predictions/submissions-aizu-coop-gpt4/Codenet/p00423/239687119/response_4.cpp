#include <iostream>
#include <list>

int main() {
  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  std::list<int> list_a, list_b;

  do {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b)
        a += game_a + game_b;
      else
        b += game_a + game_b;
    }
    list_a.push_back(a);
    list_b.push_back(b);
    a = 0;
    b = 0;
  } while (n != 0);

  auto iter_a = list_a.begin();
  auto iter_b = list_b.begin();

  for (; iter_a != list_a.end() && iter_b != list_b.end(); ++iter_a, ++iter_b) {
    std::cout << *iter_a << " " << *iter_b << std::endl;
  }

  return 0;
}