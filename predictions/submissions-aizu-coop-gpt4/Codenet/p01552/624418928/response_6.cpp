// ... Code before ...

struct item {
  unordered_map<string, shared_ptr<item>> children;
  string val;
  bool is_str;
};

// ... Code between ...

void mapping_item(string &s, int &i, shared_ptr<item> &itm, int n) {
  indent(s, i, n);
  shared_ptr<item> itm_ = make_shared<item>();
  itm_->val = key(s, i);
  itm->children[itm_->val] = itm_;
  
  // ... Rest of the function ...
}

// ... Code between ...

void solve() {
  string qry;
  cin >> qry;
  cin.ignore();
  shared_ptr<item> root = make_shared<item>();
  root->val = "root";
  string line;
  int idx = 0;
  while (getline(cin, line)) {
    line += '\n';
    yaml(line, idx, root);
  }
  
  // ... Rest of the function ...
}

// ... Rest of the code ...