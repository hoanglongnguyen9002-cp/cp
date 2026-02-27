// https://oj.vnoi.info/problem/codetour24_f_d#submit
#include <bits/stdc++.h>
using namespace std;

const long long md = 1e9 + 7;
const int N = 2e5 + 5;
long long dp[N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = ' ' + s;
        memset(dp, 0, sizeof(dp));
        dp[n + 1][1] = 1;
        int SUM_O_KO = 0;
        int SUM_O_OK = 0;
        int SUM_K_OK = 0;
        int SUM_K_KO = 0;
        for (int i = n; i >= 1; --i) {
            dp[i][1] = dp[i + 1][1];
            dp[i][0] = dp[i + 1][0];
            if (s[i] == 'K') {
                // for (int j = i + 1; j <= n; ++j) {
                //     if (s[j] == 'O') {
                //         (dp[i][1] += dp[j + 1][0]) %= md;
                //         (dp[i][0] += dp[j + 1][1]) %= md;
                //     }
                // }
                (dp[i][1] += SUM_O_KO) %= md; 
                (dp[i][0] += SUM_O_OK) %= md;
                (SUM_K_KO += dp[i + 1][0]) %= md;
                (SUM_K_OK += dp[i + 1][1]) %= md;

            } else {
                // for (int j = i + 1; j <= n; ++j) {
                //     if (s[j] == 'K') {
                //         (dp[i][1] += dp[j + 1][1]) %= md;
                //         (dp[i][0] += dp[j + 1][0]) %= md;
                //     }
                // }
                (dp[i][1] += SUM_K_OK) %= md;
                (dp[i][0] += SUM_K_KO) %= md;
                (SUM_O_KO += dp[i + 1][0]) %= md;
                (SUM_O_OK += dp[i + 1][1]) %= md;
            }
        }
        
        // for (int i = 1; i <= n; ++i) cout << dp[i][0] << ' ';cout << endl;
        // for (int i = 1; i <= n; ++i) cout << dp[i][1] << ' ';cout << endl;
        cout << dp[1][1] << '\n'; 
    }
    return 0;
}
