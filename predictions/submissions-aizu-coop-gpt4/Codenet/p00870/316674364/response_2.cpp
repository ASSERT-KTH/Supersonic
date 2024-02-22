// Optimized version of the crspt function
P crspt(P a, P b, P c, P d) {
  b -= a, d -= c;
  return a + b * crs(d, c - a) / crs(d, b);
}

// Reuse the gha array instead of allocating a new one
rep(i, SZ(text)) gha[i + 1] = gha[i] * 31 + text[i];

// Remove the unnecessary code block
// rep(jjj, m) {
//   string a;
//   cin >> a;
//   rep(i, SZ(a)) gha[i + 1] = gha[i] * 31 + a[i];
// }

// Optimize the line structure
typedef pair<P, P> line;