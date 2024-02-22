void yaml(string& s, int& i, item& itm) {
  stack<pair<int, item*>> st;
  st.push({0, &itm});

  while (!st.empty()) {
    int n = st.top().first;
    item* cur = st.top().second;
    st.pop();

    mapping_item(s, i, *cur, n);

    if (i != s.size() && is_indent_n(s, i, n)) {
      st.push({n, cur});
    }
  }
}