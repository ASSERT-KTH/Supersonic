#include <cstdio>
#include <unordered_set>
#include <string>

int main() {
  int n;
  scanf("%d", &n);
  std::unordered_set<std::string> Dic;
  char com[2], word[20];
  while (n--) {
    scanf("%1s %19s", com, word);
    if (com[0] == 'i')
      Dic.insert(word);
    else {
      if (Dic.find(word) != Dic.end())
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}