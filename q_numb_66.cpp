#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> distinct;

    for (int num : nums) {
        if (distinct.empty() || distinct.back() != num) {
            distinct.push_back(num);
        }
    }

    int n = distinct.size();

    if (n >= 3) {
        return distinct[n - 3];
    }

    return distinct[n - 1];
}

int main() {
    vector<int> nums = {2, 2, 3, 1};

    cout << thirdMax(nums);

    return 0;
}