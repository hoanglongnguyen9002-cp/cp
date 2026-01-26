// https://codeforces.com/contest/2189/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x;
        cin >> n >> x;
        long long mx = 0, pos = 0;
        for (int i = 0; i < n; ++i) {
            long long a, b, c;
            cin >> a >> b >> c;
            pos += a * (b - 1);
            mx = max(mx, a * b - c);
        }
        long long remainder = x - pos;
        if (remainder <= 0) cout << 0 << '\n';
        else if (mx <= 0) cout << -1 << '\n';
        else cout << (remainder + mx - 1) / mx << '\n';
    }
    return 0;
}