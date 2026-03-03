// https://oj.vnoi.info/problem/dp_advanced_p2_a#submit
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 3005;
int n, a[N], pref[N], dp[N][N], opt[N][N];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = INF;
        }
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int sum = pref[j] - pref[i - 1];
//            for (int k = i; k < j; ++k) {
//                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum * sum);
//            }
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + sum * sum) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum * sum;
                    opt[i][j] = k;
                }
            }
        }
    }


    cout << dp[1][n];

    return 0;
}
