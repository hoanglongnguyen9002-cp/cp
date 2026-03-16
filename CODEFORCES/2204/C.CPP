#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll lcm_ab = lcm(a, b);
        ll lcm_ac = lcm(a, c);
        ll lcm_bc = lcm(b, c);
        ll lcm_abc = lcm(a, lcm_bc);
        cout << 6 * (m / a) - 3 * (m / lcm_ab) - 3 * (m / lcm_ac) + 2 * (m / lcm_abc) << ' ';
        cout << 6 * (m / b) - 3 * (m / lcm_ab) - 3 * (m / lcm_bc) + 2 * (m / lcm_abc) << ' ';
        cout << 6 * (m / c) - 3 * (m / lcm_ac) - 3 * (m / lcm_bc) + 2 * (m / lcm_abc) << '\n';
    }
    return 0;
}
