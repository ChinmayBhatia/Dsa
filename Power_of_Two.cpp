#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        while (n > 1) {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << (sol.isPowerOfTwo(n) ? "true" : "false");

    return 0;
}