string key(string &s, int &i) {
  int start = i;
  while (isalphabet(s[i]) or isdigit(s[i])) {
    ++i;
  }
  return s.substr(start, i - start);
}

string string_(string &s, int &i) {
  int start = i;
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    ++i;
  }
  return s.substr(start, i - start);
}

void indent(string &s, int &i, int n) {
  for (int j = 0; j < n; ++j) {
    assert(s[i] == ' ');
    ++i;
  }
}