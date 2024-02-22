// ... (omitted the unchanged parts)

struct item {
  vector<unique_ptr<item>> ptr;
  string val;
  bool is_str;
};

// ... (omitted the unchanged parts)

void mapping_item(string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  auto itm_ = make_unique<item>();
  itm_->val = key(s, i);
  itm.ptr.push_back(std::move(itm_));
  // ... (omitted the unchanged parts)
  
  if (s[i] == ' ') {
    ++i;
    auto str = make_unique<item>();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr.push_back(std::move(str));
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ')
      ++j;
    assert(n < j - i);
    mapping(s, i, *itm_, j - i);
  }
} 

// ... (omitted the unchanged parts)

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
  {
    int idx = 0;
    yaml(yaml_str, idx, root);
  }
  // ...

  if (!ok) {
    cout << "no such property\n";
    return;
  }
  if (idx == qry.size()) {
    item *obj = itm->ptr.front().get();
    if (obj->is_str)
      cout << "string \"" << obj->val << "\"\n";
    else
      cout << "object\n";
    return;
  }
  ++idx;
}

// ...