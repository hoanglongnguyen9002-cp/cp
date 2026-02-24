// https://oj.vnoi.info/problem/gl_numrect#submit
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        cout << n * (n + 1) * m * (m + 1) / 4 << '\n';
    }
    return 0;
}
