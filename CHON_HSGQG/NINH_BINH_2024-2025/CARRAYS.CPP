// https://codeforces.com/group/6iRxenZ3op/contest/676495/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const long long md = 1e9 + 7;
long long dp[N], pref[N];

long long mul(long long a, long long b) {
    return (a * b) % md;
}

long long add(long long a, long long b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1) return mul(power(a, b - 1), a);
    long long x = power(a, b / 2);
    return mul(x, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("CARRAYS.INP", "r", stdin);
    freopen("CARRAYS.OUT", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    dp[1] = m;
    for (int i = 2; i <= k; ++i) dp[i] = mul(dp[i - 1], m);
    dp[k] -= m;

    for (int i = 1; i <= k; ++i) pref[i] = add(pref[i - 1], dp[i]);

    for (int i = k + 1; i <= n; ++i) {
        dp[i] = mul(m - 1, add(pref[i - 1] - pref[i - k], md));
        pref[i] = add(pref[i - 1], dp[i]);
    }
    cout << add(power(m, n) - dp[n], md);

    return 0;
}
