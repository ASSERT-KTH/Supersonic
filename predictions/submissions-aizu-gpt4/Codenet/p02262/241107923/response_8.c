#include <vector>
#include <iostream>
#include <algorithm>

void insertionSort(std::vector<int>& data, int gap);
void shellSort(std::vector<int>& data);
std::vector<int> gapSequence(int size);

int main() {
    int num;
    std::cin >> num;

    std::vector<int> data(num);
    for (int i = 0; i < num; i++)
        std::cin >> data[i];

    shellSort(data);

    for (int i = 0; i < num; i++)
        std::cout << data[i] << std::endl;

    return 0;
}

std::vector<int> gapSequence(int size) {
    std::vector<int> gaps;
    for (int gap = size/2; gap > 0; gap /= 2)
        gaps.push_back(gap);
    return gaps;
}

void shellSort(std::vector<int>& data) {
    std::vector<int> gaps = gapSequence(data.size());
    for (int gap : gaps)
        insertionSort(data, gap);
}

void insertionSort(std::vector<int>& data, int gap) {
    for (int i = gap; i < data.size(); i++) {
        int temp = data[i];
        int j = i;
        while (j >= gap && data[j - gap] > temp) {
            data[j] = data[j - gap];
            j -= gap;
        }
        data[j] = temp;
    }
}