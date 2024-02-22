#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)

// ...

struct item {
  vector<unique_ptr<item>> ptr;
  string val;
  bool is_str;
};

// ...

void mapping(string &s, int &i, item &itm, int n) {
  bool is_indent = is_indent_n(s, i, n);
  mapping_item(s, i, itm, n);
  if (i != s.size() and is_indent)
    mapping(s, i, itm, n);
}

// ...

void mapping_item(string &s, int &i, item &itm, int n) {
  // ...
  unique_ptr<item> itm_ = make_unique<item>();
  itm_->val = key(s, i);
  itm.ptr.push_back(move(itm_));
  // ...
}

// ...

void solve() {
  // ...
  ostringstream yaml_str_stream;
  {
    string buf;
    while (getline(cin, buf)) {
      yaml_str_stream << buf << '\n';
    }
  }
  string yaml_str = yaml_str_stream.str();
  // ...
}

int main() {
  // ...
}