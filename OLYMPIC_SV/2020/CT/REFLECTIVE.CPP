#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long INF = 1e18;
const int N = 1e5 + 5;

ll calc(ll n) {
    ll tmp = 0;
    while (n > 0) {
        tmp = tmp + (n / 2);
        n = n / 2;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll lf, rt;
    cin >> lf >> rt;

    cout << calc(rt) - calc(lf - 1) << '\n';

    return 0;
}
