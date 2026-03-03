// https://codeforces.com/group/6iRxenZ3op/contest/674696/problem/A
#include <bits/stdc++.h>
using namespace std;

#define int long long 

int power(int a, int b, int md) {
    if (b == 0) return 1;
    int res = power(a, b / 2, md) % md;
    res = (res * res) % md;
    if (b & 1) return (res * a) % md;
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("NTHDIGIT.INP", "r", stdin);
    freopen("NTHDIGIT.OUT", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << 0 << '\n';
            continue;
        }
        cout << power(10, n - 1, k) * 10 / k << '\n';
    }

    return 0;
}