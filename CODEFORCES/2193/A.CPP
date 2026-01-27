// https://codeforces.com/contest/2193/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s, x;
        cin >> n >> s >> x;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            sum += val; 
        }
        int remainder = s - sum;
        if (remainder < 0 || remainder % x != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}