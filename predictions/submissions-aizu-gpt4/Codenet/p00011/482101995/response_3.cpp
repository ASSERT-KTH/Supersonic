#include <iostream>
#include <vector>
#include <algorithm>

struct THorizonalLine {
    int Left;
    int Right;
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); 

    int w, n;
    std::cin >> w >> n;
    std::vector<int> StartingPoint(w);

    for (int i = 0; i < w; i++)
        StartingPoint[i] = i + 1;

    THorizonalLine HorizonalLine;
    char Dummy;

    for (int i = 0; i < n; i++) {
        std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
        std::swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
    }

    for (const auto &point : StartingPoint)
        std::cout << point << '\n';

    return 0;
}