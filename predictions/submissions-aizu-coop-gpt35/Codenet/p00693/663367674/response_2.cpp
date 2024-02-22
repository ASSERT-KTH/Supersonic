bool stringCmp(const std::string& base, const std::string& comp) {
  if (base.length() != comp.length())
    return false;
  for (int i = 0; i < base.length(); i++) {
    if (base[i] != '?' && base[i] != comp[i])
      return false;
  }
  return true;
}