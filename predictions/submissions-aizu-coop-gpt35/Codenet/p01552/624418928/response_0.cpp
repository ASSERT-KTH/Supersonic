#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct item {
  map<string, item> children;
  string val;
  bool is_str;
};

bool isalphabet(char ch) {
  return 'a' <= ch && ch <= 'z';
}

bool is_indent_n(const string& s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() || s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
}

void yaml(const string& s, item& itm) {
  stringstream ss(s);
  string line;
  vector<item*> stack;
  stack.push_back(&itm);

  while (getline(ss, line)) {
    int n = 0;
    while (line[n] == ' ')
      n++;

    if (n < stack.size()) {
      stack.resize(n + 1);
    } else if (n > stack.size()) {
      cout << "Invalid indentation" << endl;
      return;
    }

    item* parent = stack[n - 1];
    item& child = parent->children[key(line)];
    stack[n] = &child;
    child.val = value(line);
    child.is_str = !child.children.empty();
  }
}

string key(const string& line) {
  size_t i = 0;
  while (isalphabet(line[i]) || isdigit(line[i])) {
    i++;
  }
  return line.substr(0, i);
}

string value(const string& line) {
  size_t i = line.find(':');
  i++;
  while (i < line.size() && line[i] == ' ') {
    i++;
  }
  return line.substr(i);
}

void solve() {
  string qry, yaml_str;
  cin >> qry;
  cin.ignore();
  {
    string buf;
    while (getline(cin, buf)) {
      yaml_str += buf;
      yaml_str += '\n';
    }
  }
  item root;
  root.val = "root";
  yaml(yaml_str, root);

  {
    item* itm = &root;
    int idx = 1;
    while (true) {
      string str = qry.substr(idx);
      bool ok = false;
      for (auto& child : itm->children) {
        if (!child.second.is_str && child.first == str) {
          itm = &child.second;
          ok = true;
          break;
        }
      }
      if (!ok) {
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
      idx++;
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