// Before
for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
  a = strlen(s);
  // ...
}

// After
for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
  a = strlen(s);
  int len = a; // Calculate and store the length of the string
  // ...
}