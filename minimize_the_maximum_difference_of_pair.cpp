#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakePairs(vector<int>& nums, int p, int diff) {
    int count = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] - nums[i] <= diff) {
            count++;
            i++;
        }
    }

    return count >= p;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.back() - nums.front();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canMakePairs(nums, p, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main() {
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;

    cout << minimizeMax(nums, p) << endl;

    return 0;
}