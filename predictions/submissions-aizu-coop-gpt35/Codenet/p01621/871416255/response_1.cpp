#include <iostream>
#include <iomanip>
#include <cmath>

constexpr int MAX_MINUTES = 7 * 24 * 60;

bool minutes[MAX_MINUTES];

double ck(int start, int s, int t, int m, int n, int p) {
    int cnt = 0;
    for (int i = 0; i < m; i++, start += t) {
        bool flag = true;
        for (int j = 0; j < s; j++) {
            if (!minutes[(start + j) % MAX_MINUTES]) {
                flag = false;
                break;
            }
        }
        cnt += flag;
    }
    return (1.0 - pow(1.0 - 1.0 / p, static_cast<double>(cnt * n)));
}

int main() {
    std::string weekday, time;
    int s, n, t, m, p;

    while (std::cin >> s >> n >> t >> weekday >> time >> p >> m && m) {
        int wbits, tbits;
        if (weekday == "All")
            wbits = (1 << 7) - 1;
        else
            wbits = 1;

        if (time == "Night")
            tbits = 1;
        else if (time == "Day")
            tbits = 2;
        else
            tbits = 3;

        double maxProbability = 0.0;
        for (int i = MAX_MINUTES - 1; i >= 0; i--) {
            if ((wbits & (1 << (i / 1440))) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
                minutes[i] = true;
            else
                minutes[i] = false;
        }

        for (int i = 24 * 60 - 1; i >= 0; i--) {
            maxProbability = std::max(maxProbability, ck(i, s, t, m, n, p));
        }

        std::cout << std::fixed << std::setprecision(16) << maxProbability << std::endl;
    }
}