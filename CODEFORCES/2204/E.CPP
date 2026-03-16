#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int cnt[20], cnt2[20], cnt3[20];

int calc(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            cout << s << '\n';
            continue;
        }

        fill(cnt, cnt + 15, 0);
        ll sum = 0;
        for (char c : s) {
            sum += (c - '0');
            cnt[c - '0']++;
        }
        for (int i = 1; i <= sum; ++i) {
            vector<int> pos;
            int cur = i;
            ll tot = i;
            pos.push_back(cur);
            while (cur > 9) {
                cur = calc(cur);
                pos.push_back(cur);
                tot += cur;
            }
            tot += cur;

            // cur_sum = all_sum
            if (tot == sum) {
                fill(cnt2, cnt2 + 15, 0);
                for (int x : pos) {
                    string tmp = to_string(x);
                    for (char c : tmp) cnt2[c - '0']++;
                }
                bool check = false;
                for (int d = 0; d < 10; ++d) {
                    if (cnt[d] < cnt2[d]) {
                        check = true;
                        break;
                    }
                }
                if (!check) {
                    fill(cnt3, cnt3 + 15, 0);
                    for (int d = 0; d < 10; ++d) cnt3[d] = cnt[d] - cnt2[d];
                    string ans = "";
                    for (int d = 9; d >= 1; --d) {
                        while (cnt3[d] > 0) {
                            ans += to_string(d);
                            cnt3[d]--;
                        }
                    }

                    while (cnt3[0] > 0) {
                        ans += "0";
                        cnt3[0]--;
                    }

                    cout << ans;
                    for (int num : pos) {
                        cout << num;
                    }
                    cout << '\n';
                    break;

                }
            }
        }
    }
    return 0;
}
