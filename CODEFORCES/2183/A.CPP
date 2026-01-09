// https://codeforces.com/contest/2183/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (a[0] + a[n - 1] > 0) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}