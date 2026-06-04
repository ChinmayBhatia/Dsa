#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;

        for (int x : nums2) {
            freq[x]++;
        }
    }

    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;

        for (int x : nums1) {
            ans += freq[tot - x];
        }

        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};

    FindSumPairs obj(nums1, nums2);

    cout << "count(7) = " << obj.count(7) << endl;

    obj.add(3, 2);  // nums2[3] = 2 + 2 = 4

    cout << "count(8) = " << obj.count(8) << endl;

    obj.add(0, 1);  // nums2[0] = 1 + 1 = 2

    cout << "count(7) = " << obj.count(7) << endl;

    return 0;
}