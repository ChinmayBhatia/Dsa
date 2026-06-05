#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[20][11][11][2];
    long long cnt[20][11][11][2];
    string s;

    pair<long long, long long> dfs(int pos, int prev1, int prev2,
                                   bool started, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && dp[pos][prev1][prev2][started] != -1) {
            return {
                cnt[pos][prev1][prev2][started],
                dp[pos][prev1][prev2][started]
            };
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long ways = 0;
        long long waviness = 0;

        for (int d = 0; d <= limit; d++) {
            bool nStarted = started || d != 0;

            if (!started && !nStarted) {
                auto [w, v] = dfs(pos + 1, 10, 10, false,
                                  tight && d == limit);
                ways += w;
                waviness += v;
                continue;
            }

            int nPrev1, nPrev2;
            long long add = 0;

            if (!started) {
                nPrev1 = d;
                nPrev2 = 10;
            } else {
                if (prev2 != 10) {
                    if ((prev2 < prev1 && prev1 > d) ||
                        (prev2 > prev1 && prev1 < d))
                        add = 1;
                }

                nPrev2 = prev1;
                nPrev1 = d;
            }

            auto [w, v] = dfs(pos + 1, nPrev1, nPrev2,
                              true, tight && d == limit);

            ways += w;
            waviness += v + add * w;
        }

        if (!tight) {
            cnt[pos][prev1][prev2][started] = ways;
            dp[pos][prev1][prev2][started] = waviness;
        }

        return {ways, waviness};
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);

        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        return dfs(0, 10, 10, false, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};

int main() {
    long long num1, num2;
    cin >> num1 >> num2;

    Solution sol;
    cout << sol.totalWaviness(num1, num2) << endl;

    return 0;
}