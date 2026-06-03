#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int num : nums2) {
            if (s.count(num)) {
                ans.push_back(num);
                s.erase(num); // prevents duplicates
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution obj;
    vector<int> result = obj.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}