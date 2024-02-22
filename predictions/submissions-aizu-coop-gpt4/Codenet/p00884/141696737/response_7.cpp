#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

// New data structure to represent groups and their members
unordered_map<string, vector<string>> groups;

// Function to perform DFS on the groups graph
vector<string> dfs(const string& root) {
    vector<string> members;
    stack<string> s;
    unordered_set<string> visited;

    s.push(root);
    while (!s.empty()) {
        string group = s.top(); s.pop();
        if (visited.count(group) == 0) {
            visited.insert(group);
            members.push_back(group);
            for (const string& member : groups[group]) {
                s.push(member);
            }
        }
    }

    return members;
}

int main() {
    while (1) {
        int N;
        cin >> N;
        if (!N)
            break;

        groups.clear();
        for (int i = 0; i < N; ++i) {
            string st;
            cin >> st;

            string groupName;
            vector<string> memberNames;
            int prev = 0;
            for (int j = 0; j < st.size(); ++j) {
                if (st[j] == ':') {
                    groupName = st.substr(0, j);
                    prev = j;
                } else if (st[j] == ',' || st[j] == '.') {
                    memberNames.push_back(st.substr(prev + 1, j - prev - 1));
                    prev = j;
                }
            }
            groups[groupName] = memberNames;
        }

        vector<string> allMembers = dfs("0");
        sort(allMembers.begin(), allMembers.end());

        // Use unique to remove duplicates and erase to remove the empty spaces
        allMembers.erase(unique(allMembers.begin(), allMembers.end()), allMembers.end());

        cout << allMembers.size() << endl;
    }

    return 0;
}