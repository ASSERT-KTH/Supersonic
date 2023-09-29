#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> groups;
unordered_map<string, unordered_set<string>> members;

void dfs(const string& group, unordered_set<string>& allMembers) {
    if (members.find(group) == members.end()) {
        allMembers.insert(group);
        return;
    }
    for (const auto& member : members[group]) {
        if (allMembers.find(member) == allMembers.end()) {
            dfs(member, allMembers);
        }
    }
}

int main() {
    int N;
    while (cin >> N && N) {
        string group, member;
        char c;

        groups.clear();
        members.clear();

        while (N--) {
            cin >> group;
            group.pop_back();
            while (cin >> member >> c && c != '.') {
                member.pop_back();
                groups[group].push_back(member);
                members[group].insert(member);
            }
        }

        unordered_set<string> allMembers;
        dfs(groups.begin()->first, allMembers);

        cout << allMembers.size() << endl;
    }
    return 0;
}