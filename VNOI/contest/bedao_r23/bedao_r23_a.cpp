// https://oj.vnoi.info/problem/bedao_r23_a#submit
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        char d;
        int x;
        cin >> d >> x;
        if (d == 'L') {
            if (pos == 0) {
                ans += x / 100;
            } else {
                int rem = x - pos;
                if (rem >= 0) ans += rem / 100 + 1;
            }
            pos = (pos - x % 100 + 100) % 100;
        } else {
            pos += x;
            ans += pos / 100;
            pos %= 100;
        }
        // cerr << pos << ' ' << ans << endl;
    }
    cout << ans;
    return 0;
}
