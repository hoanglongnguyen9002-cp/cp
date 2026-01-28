// https://codeforces.com/contest/2158/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, y, r;
        cin >> n >> y >> r;
        cout << min(n, y / 2 + r) << '\n';
    }
    return 0;
}