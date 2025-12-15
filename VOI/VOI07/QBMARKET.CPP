#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int s, n, c[N], m[N];
__int128 dp[100001], pre_dp[100001];

void ans() {
    __int128 x = dp[0];
    string s = "";
    while (x > 0) {
        s += char('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i] >> m[i];
    dp[s] = 1;
    for (int i = 1; i <= n; ++i) {
        copy(dp, dp + 1 + s, pre_dp);
        fill(dp, dp + 1 + s, 0);
        for (int w = 0; w <= s; ++w) {
            if (pre_dp[w] == 0) continue;
            for (int k = 0; k <= m[i]; ++k) {
                int new_w = w - k * c[i];
                if (new_w < 0) break;
                dp[new_w] += pre_dp[w];
            }
        }
    }
    ans();
    return 0;
}

