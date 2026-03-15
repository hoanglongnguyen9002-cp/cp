#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long md = 1e9 + 7;
const int N = 1e6 + 6;

int n, a[N], prime[N];
map<int,int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("SECRCD.INP", "r", stdin);
    freopen("SECRCD.OUT", "w", stdout);
    iota(prime, prime + N, 0);
    for (int i = 2; i * i < N; ++i) {
        if (prime[i] == i) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int x = a[i], d = 2;
        while (x > 1) {
            d = prime[x];
            int cnt = 0;
            while (x % d == 0) {
                x /= d;
                cnt++;
            }
            mp[d] += cnt;
        }
    }

    ll ans = 1;
    for (pair<int,int> x : mp) (ans *= (x.second + 1)) %= md;
    cout << ans;

    return 0;
}
