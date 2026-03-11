// https://codeforces.com/group/6iRxenZ3op/contest/677478/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
long long cnt[25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("LUCKY.INP", "r", stdin);
    freopen("LUCKY.OUT", "w", stdout);

    cin >> n >> m;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int d = 0;
        for (int j = 0; j < m; ++j) if (s[j] == 'Y') d++;
        for (int j = 0; j <= m; ++j) if ((d - j) & 1) ans += cnt[j];
        cnt[d]++;
    }

    cout << ans;

    return 0;
}
