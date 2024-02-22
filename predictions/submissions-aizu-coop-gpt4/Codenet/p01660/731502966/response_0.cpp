for (int r = 0; r < 6; r++) {
    int path1 = checkPath(from + dice[r]);
    int path2 = checkPath(from - dice[r]);
    bestpath = min(bestpath, min(path1, path2));
}