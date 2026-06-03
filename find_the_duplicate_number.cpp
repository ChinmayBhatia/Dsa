#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution obj;
    int result = obj.findDuplicate(nums);

    cout << "Duplicate Number: " << result << endl;

    return 0;
}