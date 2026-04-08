#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long INF = 1e18;
const int N = 100005;

int a[N], pref[N], suff[N];
int n;
ll m;

ll calc(int x) {
    pref[1] = a[1];
    if (x > pref[1]) pref[1] = x;
    for (int i = 2; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (a[i] > pref[i]) pref[i] = a[i];
        if (x > pref[i]) pref[i] = x;
    }

    suff[n] = a[n];
    if (x > suff[n]) suff[n] = x;
    for (int i = n - 1; i >= 1; --i) {
        suff[i] = suff[i + 1];
        if (a[i] > suff[i]) suff[i] = a[i];
        if (x > suff[i]) suff[i] = x;
    }

    ll tmp = 0;
    for (int i = 1; i <= n; ++i) {
        int mn = pref[i];
        if (suff[i] < mn) mn = suff[i];
        int cur = a[i];
        if (x > cur) cur = x;
        tmp = tmp + (mn - cur);
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("buildcol.inp", "r")) {
        freopen("buildcol.inp", "r", stdin);
        freopen("buildcol.out", "w", stdout);
    }

    if (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int l = 0;
        int r = 2000000005;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (calc(mid) >= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}