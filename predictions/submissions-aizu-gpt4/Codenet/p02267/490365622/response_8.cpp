#include <iostream>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q, cnt = 0;
    std::unordered_set<int> S;

    std::cin >> n;
    for(int i = 0; i < n; ++i){
        int temp;
        std::cin >> temp;
        S.insert(temp);
    }

    std::cin >> q;
    for(int j = 0; j < q; ++j){
        int temp;
        std::cin >> temp;
        if(S.find(temp) != S.end()){
            ++cnt;
        }
    }

    std::cout << cnt << "\n";
    return 0;
}