#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0;
        int neg = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    Solution obj;
    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}