#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e5 + 5;
const int md = 1e9 + 7;
ll n, C[65][65], used[65][65];

int dp(int pos, int car) {
    if (pos == 62) return car == 0 ? 1 : 0;
    if (used[pos][car] != -1) return used[pos][car];
    int res = 0;
    int bit = (n >> pos) & 1;
    int m = pos + 1;
    for (int c = 0; c <= m; ++c) {
        int sum = c + car;
        if (sum % 2 == bit) res = (res + C[m][c] * dp(pos + 1, sum / 2)) % md;
    }
    return used[pos][car] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXCHANGE.INP", "r", stdin);
    freopen("EXCHANGE.OUT", "w", stdout);
    for (int i = 0; i <= 62; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % md;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= 62; ++i) {
            for (int j = 0; j <= 62; ++j) {
                used[i][j] = -1;
            }
        }
        cout << dp(0, 0) << '\n';
    }
    return 0;
}
