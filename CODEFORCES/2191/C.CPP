// https://codeforces.com/contest/2191/problem/C
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    string t = s;
    sort(t.begin(), t.end());
    for (int i = 0; i < n; ++i) if (s[i] == '0') cnt++;
    if (cnt == n || cnt == 0 || t == s) {
        cout << "Bob\n";
        return;
    }   
    cout << "Alice\n";
    vector<int> ans;
    for (int i = 0; i < cnt; ++i) if (s[i] == '1') ans.push_back(i + 1);
    for (int i = cnt; i < n; ++i) if (s[i] == '0') ans.push_back(i + 1);
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}