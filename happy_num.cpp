#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getSum(n);
        }

        return n == 1;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << "Happy Number\n";
    else
        cout << "Not a Happy Number\n";

    return 0;
}