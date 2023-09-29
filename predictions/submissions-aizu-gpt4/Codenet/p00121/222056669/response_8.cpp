#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct State {
    char data[9];
    int emptyIndex;
    int step;

    State(char* d, int ei, int s) {
        strcpy(data, d);
        emptyIndex = ei;
        step = s;
    }

    bool operator == (const State& other) const {
        return strcmp(data, other.data) == 0;
    }

    State swap(int i, int j) {
        char newData[9];
        strcpy(newData, data);
        swap(newData[i], newData[j]);
        return State(newData, j, step + 1);
    }
};

int dx[4] = {-1, 1, -3, 3};

int bfs(State start, State goal) {
    if(start == goal) return start.step;
    queue<State> q;
    q.push(start);
    while(!q.empty()) {
        State current = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int newEmptyIndex = current.emptyIndex + dx[i];
            if(newEmptyIndex < 0 || newEmptyIndex > 7 || (current.emptyIndex == 2 && i == 1) || (current.emptyIndex == 5 && i == 1) || (current.emptyIndex == 3 && i == 0) || (current.emptyIndex == 6 && i == 0)) continue;
            State newState = current.swap(current.emptyIndex, newEmptyIndex);
            if(newState == goal) return newState.step;
            q.push(newState);
        }
    }
    return -1;
}

int main() {
    char startData[9], goalData[9] = "12345670";
    while(scanf("%s", startData) != EOF) {
        int startEmptyIndex = strchr(startData, '0') - startData;
        State startState = State(startData, startEmptyIndex, 0);
        int startGoalIndex = strchr(goalData, '0') - goalData;
        State goalState = State(goalData, startGoalIndex, 0);
        int result = bfs(startState, goalState);
        printf("%d\n", result);
    }
    return 0;
}