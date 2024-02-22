void mul(Mat &res, const Mat &a, const Mat &b) {
    int N = a.size();
    for_(i, 0, N) 
        for_(j, 0, N) 
            for_(k, 0, N) {
                if (a[i][k] >= 0 && b[k][j] >= 0)
                    maxUpdate(res[i][j], a[i][k] + b[k][j]);
            }
}