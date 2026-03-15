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
        map<int,int> mp;
        int mx = 0;
        for (int i = 0; i < n * n; ++i) {
            int x;
            cin >> x;
            mp[x]++;
            mx = max(mx, mp[x]);
        }
        if (n * (n - 1) < mx) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
