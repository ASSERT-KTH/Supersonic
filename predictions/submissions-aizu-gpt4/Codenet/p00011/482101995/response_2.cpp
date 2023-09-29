#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int w;
    cin >> w;
    int n;
    cin >> n;
    vector<int> StartingPoint(w);
  
    for (int i = 0; i < w; i++)
        StartingPoint[i] = i + 1;

    int Left, Right;
    char Dummy;
  
    for (int i = 0; i < n; i++) {
        cin >> Left >> Dummy >> Right;
        swap(StartingPoint[Left - 1], StartingPoint[Right - 1]);
    }
    for (const auto &point : StartingPoint)
        cout << point << '\n';
  
    cout.flush();
    return 0;
}