#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x < 2) return x;

    long long left = 1, right = x;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Square root (integer part): " << mySqrt(x) << endl;

    return 0;
}