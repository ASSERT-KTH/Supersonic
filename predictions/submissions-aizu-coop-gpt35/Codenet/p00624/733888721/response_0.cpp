vector<vector<int>> bfscost(10, vector<int>(10, -1));
vector<vector<char>> field(16, vector<char>(16));
vector<vector<vector<vector<vector<vector<vector<vector<char>>>>>>>> DP(
    9, vector<vector<vector<vector<vector<vector<vector<char>>>>>>>(
           9, vector<vector<vector<vector<vector<vector<char>>>>>>>(
                  9, vector<vector<vector<vector<vector<char>>>>>(
                         9, vector<vector<vector<vector<char>>>>(
                                9, vector<vector<vector<char>>>>(
                                       9, vector<vector<char>>>(
                                              9, vector<char>(9, -1))))));