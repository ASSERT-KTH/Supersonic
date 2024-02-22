#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  unordered_map<string, bool> Dic;
  char com[10];
  string word;
  word.reserve(100); // Preallocate memory for the word
  
  while (n--) {
    scanf("%s", com);
    scanf("%s", &word[0]);
    
    if (com[0] == 'i')
      Dic[word] = true;
    else {
      if (Dic[word])
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}