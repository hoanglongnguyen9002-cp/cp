// https://codeforces.com/contest/2189/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        if (h > l) swap(h, l);
        int ans = 0;
        int i = 0;
        for (int j = n - 1; j > i; --j) {
            if (a[i] <= h && a[j] <= l) {
                ans++;
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}