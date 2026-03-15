// https://oj.vnoi.info/problem/bedao_r23_b#submit
#include <bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = ' ' + s + ' ';
    mp[s] = true;
    int cnt = -1;
    for (int i = 1; i <= k; ++i) {
        vector<int> a;
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == '1' && s[j + 1] == '1') {
                a.push_back(j);
            }
        }
        for (int x : a) {
            if (s[x] == '0') s[x] = '1';
            else s[x] = '0';
        }
        if (mp[s]) {
            cnt = i;
            break;
        }
        mp[s] = true;
        // cout << s << endl;
    }
    k %= cnt;
    for (int i = 1; i <= k; ++i) {
        vector<int> a;
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == '1' && s[j + 1] == '1') {
                a.push_back(j);
            }
        }
        for (int x : a) {
            if (s[x] == '0') s[x] = '1';
            else s[x] = '0';
        }
    }
    s.erase(0,1);
    cout << s;
    return 0;
}
