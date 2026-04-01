#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int t, n, a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHUNGKHOAN.INP", "r", stdin);
    freopen("CHUNGKHOAN.OUT", "w", stdout);
    cin >> t >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    deque<int> mx, mn;
    for (int l = 1, r = 1; l <= n; ++l) {
        while (r <= n) {
            int new_mx = (mx.empty() ? a[r] : max(mx.front(), a[r]));
            int new_mn = (mn.empty() ? a[r] : min(mn.front(), a[r]));
            if (new_mx - new_mn > t) break;
            while (!mx.empty() && mx.back() < a[r]) mx.pop_back();
            mx.push_back(a[r]);
            while (!mn.empty() && mn.back() > a[r]) mn.pop_back();
            mn.push_back(a[r]);
            r++;
        }
        ans = max(ans, r - l);
        if (mn.front() == a[l]) mn.pop_front();
        if (mx.front() == a[l]) mx.pop_front();
    }
    cout << ans;
    return 0;
}
