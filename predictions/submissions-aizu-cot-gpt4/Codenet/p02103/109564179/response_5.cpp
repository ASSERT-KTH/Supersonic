typedef map<ll, int>::iterator mapIter;
int cost[100000]; // Reduced size

//... rest of the program

for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
        //... rest of the loop
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            ll nval = (ll)ny * n + nx;
            mapIter iter = g.find(nval);
            if (iter != g.end()) {
                int mapValue = iter->second;
                if (cost[mapValue] == -1) {
                    cost[mapValue] = nc;
                    if (nc == 0) que.push(mapValue);
                    if (nc == 1) que2.push(mapValue);
                } else if (cost[mapValue] == 1 && nc == 0) {
                    cost[mapValue] = 0;
                    que.push(mapValue);
                }
            }
        }
    }
}

//... Apply the same modifications to other BFS functions