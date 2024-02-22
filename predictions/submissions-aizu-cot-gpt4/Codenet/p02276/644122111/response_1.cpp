#include <iostream>
#include <vector>
using namespace std;

void print_partition_ints(vector<int>& vec, unsigned int q) {
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if(i == q) 
            cout << "[" << vec[i] << "]";
        else 
            cout << vec[i];
        
        if(i != vec.size()-1)
            cout << " ";
    }
    cout << "\n";
}

unsigned int partition(vector<int>& vec) {
    unsigned int less = 0;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (vec[i] <= vec[vec.size()-1]) {
            // swapping using XOR
            vec[i] ^= vec[less];
            vec[less] ^= vec[i];
            vec[i] ^= vec[less];
            ++less;
        }
    }
    // swapping using XOR
    vec[vec.size()-1] ^= vec[less];
    vec[less] ^= vec[vec.size()-1];
    vec[vec.size()-1] ^= vec[less];
    return less;
}

int main() {
    unsigned int n;
    cin >> n;
    vector<int> vec(n);
    for (unsigned int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    unsigned int q = partition(vec);
    print_partition_ints(vec, q);
}