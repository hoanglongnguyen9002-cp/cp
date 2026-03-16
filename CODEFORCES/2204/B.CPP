#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x >= mx) {
                ans++;
                mx = x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
