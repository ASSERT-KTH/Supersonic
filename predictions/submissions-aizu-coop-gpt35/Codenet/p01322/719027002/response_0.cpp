#include <iostream>
#include <unordered_map>
#include <cstring>

// Implementation of the Knuth-Morris-Pratt (KMP) algorithm for string matching
bool kmpMatch(const char* pattern, const char* text) {
  int m = strlen(pattern);
  int n = strlen(text);
  
  // Build the longest prefix suffix array (lps)
  int lps[m];
  lps[0] = 0;
  int len = 0;
  int i = 1;
  
  while (i < m) {
    if (pattern[i] == pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  
  // Perform the string matching
  int j = 0;
  i = 0;
  
  while (i < n) {
    if (pattern[j] == text[i]) {
      j++;
      i++;
    }
    
    if (j == m) {
      return true;  // Match found
    } else if (i < n && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  
  return false;  // No match found
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int n, m;
  char b[100][9];
  int o[100];
  char l[9];
  std::unordered_map<std::string, int> map;
  
  while (true) {
    scanf("%d %d", &n, &m);
    
    if (n == 0 && m == 0)
      break;
    
    map.clear();
    
    for (int i = 0; i < n; i++) {
      scanf("%s %d", b[i], &o[i]);
      map[b[i]] = o[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < m; i++) {
      scanf("%s", l);
      
      for (int j = 0; j < n; j++) {
        if (kmpMatch(b[j], l)) {
          ans += map[b[j]];
          break;
        }
      }
    }
    
    printf("%d\n", ans);
  }
  
  return 0;
}