#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> chk;
int n;
char ins;
string s;
int dna_values[128];

void initialize_dna_values() {
  dna_values['A'] = 1;
  dna_values['C'] = 2;
  dna_values['G'] = 3;
  dna_values['T'] = 4;
}

int h(string s) {
  int ret = 0;
  for (char c : s) {
    ret = ret * 5 + dna_values[c];
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); // additional optimization to disconnect cin and cout
  initialize_dna_values();
  
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    int hash = h(s);
    if (ins == 'i') {
      chk.insert(hash);
    } else {
      cout << (chk.count(hash) ? "yes" : "no") << endl;
    }
  }
  return 0;
}