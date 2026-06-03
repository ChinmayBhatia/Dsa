#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = nums[0];
        int maxsum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currsum = max(currsum + nums[i], nums[i]);
            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;
    cout << "Maximum Subarray Sum = " << obj.maxSubArray(nums);

    return 0;
}