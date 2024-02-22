#include <iostream>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main() {
    fastIO;
    int n;
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> n;
    while (n--) {
        cin >> ax >> ay >> bx >> by;
        cin >> cx >> cy >> dx >> dy;
        double crossProduct = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
        if (crossProduct == 0)
            cout << "2\n";
        else if (crossProduct > 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}