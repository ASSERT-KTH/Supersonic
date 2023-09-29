#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::unordered_map<std::string, bool> Dic;
    std::string com, word;
    while (n--) {
        std::cin >> com >> word;
        if (com[0] == 'i')
            Dic[word] = true;
        else
            std::cout << (Dic[word] ? "yes\n" : "no\n");
    }
}