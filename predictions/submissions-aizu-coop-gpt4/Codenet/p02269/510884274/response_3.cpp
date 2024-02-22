#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
unordered_set<int> sequences;
int n;
char ins[10], s[1000];

int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret <<= 2;
    switch (c) {
      case 'A':
        ret |= 0;
        break;
      case 'C':
        ret |= 1;
        break;
      case 'G':
        ret |= 2;
        break;
      case 'T':
        ret |= 3;
        break;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%s%s", ins, s);
    string sStr(s);
    if (ins[0] == 'i') {
      sequences.insert(h(sStr));
    } else {
      printf(sequences.count(h(sStr)) ? "yes\n" : "no\n");
    }
  }
  return 0;
}