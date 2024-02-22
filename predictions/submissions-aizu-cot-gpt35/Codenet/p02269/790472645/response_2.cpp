#include <iostream>
#include <unordered_set>

int dic_op(const char* str) {
  return std::atoi(str);
}

int main() {
  int n;
  std::unordered_set<int> dic;
  char opstr[7];
  char str[13];
  std::cin >> n;
  
  for (int i = 0; i < n; i++) {
    std::cin >> opstr >> str;
    
    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.find(dic_op(str)) != dic.end()) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
  }
  
  return 0;
}