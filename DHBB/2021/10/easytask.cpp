#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e6 + 6;
int n;
ll pref[N];
bool prime[N];

void prepare() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i < N; ++i) {
        for (int j = i * i; j < N; j += i) {
            prime[j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    cin >> n;
    ll pre_min = INF, ans = -INF;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
        if (!prime[i]) {
            pre_min = min(pre_min, pref[i - 1]);
            ans = max(ans, pref[i] - pre_min);
        }
    }
    cout << ans;
    return 0;
}
