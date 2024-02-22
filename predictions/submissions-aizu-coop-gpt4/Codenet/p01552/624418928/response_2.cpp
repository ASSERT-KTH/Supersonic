#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
template <typename T> using vec = std::vector<T>;
const int inf = 1 << 30;
const long long int infll = 1LL << 62;
const double eps = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct item {
  map<string, shared_ptr<item>> children;
  string val;
  bool is_str;
};

bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }

bool is_indent_n(const string &s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() or s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
}

void yaml(vector<string> &lines, int &i, shared_ptr<item> &itm);
void mapping(vector<string> &lines, int &i, shared_ptr<item> &itm, int n);
void mapping_item(vector<string> &lines, int &i, shared_ptr<item> &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);

void yaml(vector<string> &lines, int &i, shared_ptr<item> &itm) { 
  mapping(lines, i, itm, 0); 
}

void mapping(vector<string> &lines, int &i, shared_ptr<item> &itm, int n) {
  while (i < lines.size() and is_indent_n(lines[i], 0, n)) {
    mapping_item(lines, i, itm, n);
  }
}

void mapping_item(vector<string> &lines, int &i, shared_ptr<item> &itm, int n) {
  int j = i;
  while (j != lines.size() and lines[j][0] == ' ')
    ++j;
  if (n < j - i) {
    mapping(lines, i, *itm_, j - i);
  }
}

string key(string &s, int &i) {
  string res;
  while (isalphabet(s[i]) or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string &s, int &i) {
  string res;
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string &s, int &i, int n) {
  for (; n > 0; --n, ++i) {
    assert(s[i] == ' ');
  }
}

void solve() {
  string qry;
  cin >> qry;
  cin.ignore();
  vector<string> lines;
  {
    string buf;
    while (getline(cin, buf)) {
      lines.push_back(buf);
    }
  }
  auto root = make_shared<item>();
  root->val = "root";
  {
    int idx = 0;
    yaml(lines, idx, root);
  }
  {
    auto itm = root;
    int idx = 1;
    while (true) {
      string str = string_(qry, idx);
      itm = itm->children[str];
      if (!itm) {
        cout << "no such property" << endl;
        return;
      }
      if (idx == qry.size()) {
        if (itm->is_str)
          cout << "string \"" << itm->val << "\"" << endl;
        else
          cout << "object" << endl;
        return;
      }
      ++idx;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}