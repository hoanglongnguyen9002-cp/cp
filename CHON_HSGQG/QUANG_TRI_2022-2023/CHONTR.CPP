#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int n, P, Q, R, a[N];
ll cntP, cntQ, cntR;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHONTR.INP", "r", stdin);
    freopen("CHONTR.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> P >> Q >> R;
    for (int i = n; i >= 1; --i) {
        if (a[i] == P && i < n - 1) cntP += cntQ;
        if (a[i] == Q && i < n) cntQ += cntR;
        if (a[i] == R) cntR++;
    }
    cout << cntP;
    return 0;
}
