#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Heap {
public:
    Heap() : n(0) {}

    void insert(int data) {
        array.push_back(data);
        int tmp = n;
        while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
            std::swap(array[tmp], array[(tmp - 1) / 2]);
            tmp = (tmp - 1) / 2;
        }
        ++n;
    }

    void max_heapify(int start, int end) {
        int dad = start;
        int son = dad * 2 + 1;
        while (son <= end) {
            if (array[son] < array[son + 1] && son + 1 <= end)
                ++son;
            if (array[dad] > array[son])
                return;
            else {
                std::swap(array[son], array[dad]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }

    int heap_sort(int len) {
        std::swap(array[0], array[len - 1]);
        max_heapify(0, len - 2);
        return array[len - 1];
    }

    int extract() {
        int ret = heap_sort(n);
        --n;
        array.pop_back();
        return ret;
    }

private:
    std::vector<int> array;
    int n;
};

int main() {
    std::string line;
    Heap heap;
    while (std::getline(std::cin, line)) {
        if (line[2] == 'd')
            break;
        if (line[0] == 'i') {
            heap.insert(std::stoi(line.substr(1)));
        } else {
            std::cout << heap.extract() << "\n";
        }
    }
}