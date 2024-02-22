#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> hashmap;
int n;
char ins;
string s;
int char_to_int[128];

int h(string s) {
  int ret = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret = ret * 5 + char_to_int[s[i]];
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); // This line is added to further optimize the input/output operations

  // Initialize the char_to_int array
  char_to_int[(int)'A'] = 1;
  char_to_int[(int)'C'] = 2;
  char_to_int[(int)'G'] = 3;
  char_to_int[(int)'T'] = 4;

  cin >> n;
  while (n--) {
    cin >> ins >> s;
    int hash_value = h(s);
    if (ins == 'i') {
      hashmap[hash_value] = true;
    } else {
      cout << (hashmap[hash_value] ? "yes" : "no") << '\n';
    }
  }

  return 0;
}