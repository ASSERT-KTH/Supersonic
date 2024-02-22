#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int w, h, p;
    vector<ull> used;

    int D[256];
    for (int i = 'A'; i <= 'Z'; i++)
        D[i] = i - 'A';
    for (int i = 'a'; i <= 'z'; i++)
        D[i] = i - 'a' + 26;
    for (int i = '0'; i <= '9'; i++)
        D[i] = i - '0' + 52;
    D['+'] = 62, D['/'] = 63;

    while (cin >> w >> h >> p, w) {
        used.clear();

        // Read the binary representation of the image
        vector<vector<bool>> im(h, vector<bool>(w * 6));
        string s;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = D[s[j]];
                for (int a = 0; a < 6; a++)
                    im[i][j * 6 + a] = (t >> (5 - a)) & 1;
            }
        }

        // Read the binary representation of the pattern
        vector<vector<bool>> pa(p, vector<bool>(p * 6));
        for (int i = 0; i < p; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = D[s[j]];
                for (int a = 0; a < 6; a++)
                    pa[i][j * 6 + a] = (t >> (5 - a)) & 1;
            }
        }

        // Calculate the rolling hash values for the pattern
        vector<ull> patternHash(p);
        ull g = 1;
        for (int i = 0; i < p; i++) {
            ull b = 0;
            for (int j = 0; j < p; j++)
                b = b * 2 + pa[i][j];
            patternHash[0] = patternHash[0] * 2 + b;
            if (i > 0)
                patternHash[i] = patternHash[i - 1] * (1ULL << p) + b;
            g *= 2;
        }

        int ans = 0;

        // Iterate through all possible rotations and reflections of the pattern
        for (int k = 0; k < 4; k++) {
            // Calculate the rolling hash values for the image rows
            vector<vector<ull>> rowHash(h, vector<ull>(w - p + 1));
            for (int i = 0; i < h; i++) {
                ull b = 0;
                for (int j = 0; j < p; j++)
                    b = b * 2 + im[i][j];
                rowHash[i][0] = b;
                for (int j = p; j < w; j++) {
                    b = (b - g * im[i][j - p]) * 2 + im[i][j];
                    rowHash[i][j - p + 1] = b;
                }
            }

            // Calculate the rolling hash values for the image columns
            vector<vector<ull>> colHash(w - p + 1, vector<ull>(h - p + 1));
            for (int j = 0; j < w - p + 1; j++) {
                ull b = 0, n = 1;
                for (int i = 0; i < p; i++)
                    n *= (1ULL << p);
                for (int i = 0; i < p; i++)
                    b = b * n + rowHash[i][j];
                colHash[j][0] = b;
                for (int i = p; i < h; i++) {
                    b = (b - rowHash[i - p][j] * g) * n + rowHash[i][j];
                    colHash[j][i - p + 1] = b;
                }
            }

            // Count the occurrences of the pattern
            for (int i = 0; i < h - p + 1; i++) {
                for (int j = 0; j < w - p + 1; j++) {
                    bool match = true;
                    for (int x = 0; x < p; x++) {
                        if (colHash[j][i] != patternHash[x]) {
                            match = false;
                            break;
                        }
                        j++;
                    }
                    if (match)
                        ans++;
                }
            }

            // Rotate and reflect the pattern
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p / 2; j++) {
                    swap(pa[i][j], pa[i][p - j - 1]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}