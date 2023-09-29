#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::pair<float, std::string>> weights = {
        {91, "heavy"},
        {81, "light heavy"},
        {75, "middle"},
        {69, "light middle"},
        {64, "welter"},
        {60, "light welter"},
        {57, "light"},
        {54, "feather"},
        {51, "bantam"},
        {48, "fly"}};

    float f;
    while(std::cin >> f) {
        for (auto it = weights.rbegin(); it != weights.rend(); ++it) {
            if (f > it->first) {
                std::cout << it->second << std::endl;
                break;
            }
        }
    }
    return 0;
}