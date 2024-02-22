// Before
rep(jjj, m) {
  string a;
  cin >> a;
  text += a;
}

// After
stringstream text;
rep(jjj, m) {
  string a;
  cin >> a;
  text << a;
}