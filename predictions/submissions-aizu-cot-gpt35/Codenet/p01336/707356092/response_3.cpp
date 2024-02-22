#include <iostream>
#include <vector>
#include <cstring>

static const int INF = 0x3f3f3f3f;

class Data {
public:
    const std::string& mName;
    int mC, mV, mD, mL;
    Data(const std::string& _n, int _c, int _v, int _d, int _l)
        : mName(_n), mC(_c), mV(_v), mD(_d), mL(_l) {}
};

int dp[301][3];

int main() {
    int N, M;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> N >> M;
        
        std::vector<Data> idols;
        idols.reserve(N);
        
        for (int i = 0; i < N; i++) {
            std::string name, dataLine;
            std::getline(std::cin, name);
            std::getline(std::cin, dataLine);
            
            std::stringstream dataSS(dataLine);
            int C, V, D, L;
            dataSS >> C >> V >> D >> L;
            
            idols.push_back(Data(name, C, V, D, L));
        }
        
        std::memset(dp, 0, sizeof(dp));
        
        for (int j = 0; j < idols.size(); j++) {
            for (int i = M; i >= 0; i--) {
                for (int k = 0; k <= 300; k++) {
                    if (i - idols[j].mC * k < 0)
                        break;
                    dp[i][0] = std::max(dp[i - idols[j].mC * k][0] + idols[j].mV * k, dp[i][0]);
                    dp[i][1] = std::max(dp[i - idols[j].mC * k][1] + idols[j].mD * k, dp[i][1]);
                    dp[i][2] = std::max(dp[i - idols[j].mC * k][2] + idols[j].mL * k, dp[i][2]);
                }
            }
        }
        
        int maxv = 0;
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j < 3; j++) {
                maxv = std::max(dp[i][j], maxv);
            }
        }
        
        std::printf("%d\n", maxv);
    }
    
    return 0;
}