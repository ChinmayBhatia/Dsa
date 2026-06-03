#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long prefixSum = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            long long curr = (prefixSum + i) / (i + 1);

            ans = max(ans, curr);
        }

        return (int)ans;
    }
};

int main() {
    vector<int> nums = {3, 7, 1, 6};

    Solution obj;
    cout << obj.minimizeArrayValue(nums);

    return 0;
}