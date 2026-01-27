// https://codeforces.com/contest/2193/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int val = -1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (a[i] == n - i) ans.push_back(a[i]);
            else {
                val = n - i;
                break;
            }
        }
        if (val != -1) {
            int pos = -1;
            for (int i = 0; i < n; ++i) if (a[i] == val) pos = i;
            for (int i = pos; i >= n - val; --i) ans.push_back(a[i]);
            for (int i = pos + 1; i < n; ++i) ans.push_back(a[i]);
        }
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}