#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    int expected = n * (n + 1) / 2;
    int actual = 0;

    for (int num : nums) {
        actual += num;
    }

    return expected - actual;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << missingNumber(nums);

    return 0;
}