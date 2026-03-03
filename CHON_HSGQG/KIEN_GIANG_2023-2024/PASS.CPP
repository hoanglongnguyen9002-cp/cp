// https://codeforces.com/group/6iRxenZ3op/contest/674696/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 2e4 + 4;
int n;
string s[N];
map<string,int> mp;
map<string,int> x;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("PASS.INP", "r", stdin);
    freopen("PASS.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        mp[s[i]]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        x.clear();
        for(int l = 0; l < s[i].size(); ++l) {
            for(int r = l; r < s[i].size(); ++r) {
                x[s[i].substr(l, r - l + 1)]++;
            }
        }
        for (pair<string,int> tmp : x) {
            if (mp.count(tmp.first)) ans += mp[tmp.first];
        }
        ans--; 
    }

    cout << ans;
    return 0;
}