#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
ll m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("LIKENUM.INP", "r", stdin);
    freopen("LIKENUM.OUT", "w", stdout);
    cin >> x >> m;
    if (x >= m) {
        cout << 0;
        return 0;
    }
    string s = to_string(x);
    int target = s.size();
    ll p = 1;
    for (int i = 1; i <= target; ++i) p *= 10;
    ll ans = 0;
    ll pref = m / p;
    if (m >= (pref * p + x)) ans = pref;
    else ans = pref - 1;
    cout << ans;
    return 0;
}
