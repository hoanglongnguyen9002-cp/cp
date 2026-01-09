// https://codeforces.com/contest/2183/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        int mex = 0;
        while (a[mex]) mex++;
        cout << min(mex, k - 1) << '\n';
    }
    return 0;
}