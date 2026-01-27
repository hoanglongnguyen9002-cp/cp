// https://codeforces.com/contest/2193/problem/C
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) c[i] = max(a[i], b[i]);
        int mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            mx = max(mx, c[i]);
            c[i] = mx;
        }
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + c[i - 1];
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}