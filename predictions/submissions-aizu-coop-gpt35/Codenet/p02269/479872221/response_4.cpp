bool compareStrings(const char* str1, const char* str2) {
  for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return false;
    }
  }
  return str1[i] == str2[i];
}