#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][0] <= ans.back()[1]) {

            ans.back()[1] =
                max(ans.back()[1], intervals[i][1]);

        } else {

            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> result =
        mergeIntervals(intervals);

    cout << "Merged Intervals:\n";

    for (auto interval : result) {
        cout << "[" << interval[0]
             << "," << interval[1] << "] ";
    }

    return 0;
}