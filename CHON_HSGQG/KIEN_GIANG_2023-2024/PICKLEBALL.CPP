// https://codeforces.com/group/6iRxenZ3op/contest/674259/problem/A
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("PICKLEBALL.INP", "r", stdin);
    freopen("PICKLEBALL.OUT", "w", stdout);

    cin >> n >> s;

    if (n <= 20) {
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') x |= (1 << (n - i - 1));
        }
    
        int MASK = (1 << n);
        int ans = 1e8;
        for (int mask = 0; mask < MASK; ++mask) {
            if ((mask | x) != x) continue;
            int prev = mask;
            // cout << bitset<10>(mask) << endl;
            while (true) {
                if (mask == x) {
                    ans = min(ans, __builtin_popcount(prev));
                    break;
                }
                int next = mask;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        if (i - 1 >= 0) next |= (1 << (i - 1));
                        if (i + 1 < n)  next |= (1 << (i + 1));
                    }
                }
                if (next == mask || (mask | x) != x) break;
                mask = next;
            }
            mask = prev;
        }
        cout << ans;
    
        return 0;
    }

    int len = 0;
    int st = 0, fn = s.size() - 1;
    int day = 1e8;

    if (s[0] == '1') {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') len++;
            else {
                st = i;
                break;
            }
        }
        len -= 1;
        day = len;
    }

    len = 0;
    if (s.back() == '1') {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '1') len++;
            else {
                fn = i;
                break;
            }
        }
        len -= 1;
        day = min(day, len);
    }


    len = 0;
    int mn = 1e8;
    for (int i = st; i <= fn; ++i) {
        if (s[i] == '1') {
            len++;
        } else {
            if (len != 0) mn = min(mn, len);
            len = 0;
        }
    }
    if (len != 0) mn = min(mn, len);
    if (mn & 1) mn -= 1;
    else mn -= 2;
    mn /= 2;
    
    day = min(day, mn);
    // cout << day << endl;

    int ans = 0;
    len = 0;
    for (char c : s) {
        if (c == '1') {
            len++;
        } else {
            if (len != 0) {
                int x = 2 * day + 1;
                ans += (len + x - 1) / x;
            }
            len = 0;
        }
    }
    if (len != 0) {
        int x = 2 * day + 1;
        ans += (len + x - 1) / x;
    }
    cout << ans;
    return 0;
}