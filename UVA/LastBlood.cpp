#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Submission {
    int time;
    int teamID;
    char problem;
    string verdict;
};

int main() {
    int n, t, m;
    cin >> n >> t >> m;

    vector<Submission> submissions(m);
    for (int i = 0; i < m; ++i) {
        cin >> submissions[i].time >> submissions[i].teamID >> submissions[i].problem >> submissions[i].verdict;
    }

    map<char, pair<int, int>> lastBlood; // problem -> (time, teamID)

    map<char, map<int, int>> firstAcceptedTime; // problem -> (teamID -> time)

    for (const auto& sub : submissions) {
        if (sub.verdict == "Yes") {
            if (firstAcceptedTime[sub.problem].find(sub.teamID) == firstAcceptedTime[sub.problem].end()) {
                // First time this team solved the problem
                firstAcceptedTime[sub.problem][sub.teamID] = sub.time;
            }

            int acceptedTime = firstAcceptedTime[sub.problem][sub.teamID];
            if (lastBlood[sub.problem].first < acceptedTime) {
                lastBlood[sub.problem] = {acceptedTime, sub.teamID};
            }
        }
    }

    for (char problem = 'A'; problem < 'A' + n; ++problem) {
        if (lastBlood.find(problem) != lastBlood.end()) {
            cout << problem << " " << lastBlood[problem].first << " " << lastBlood[problem].second << endl;
        } else {
            cout << problem << " - -" << endl;
        }
    }

    return 0;
}
