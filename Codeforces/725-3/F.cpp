#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int a, b; cin >> a >> b;
    string s = to_string(a);
    int cnt = 0;
    for (int i = a; i < b; ++i) {
        int idx = s.size() - 1;
        s[idx]++;
        while(s[idx] == ':') {
            s[idx] = 0;
            idx--;
            if (idx < 0) {
                s.insert(s.begin(), '0');
                idx = 0;
            }
            s[idx]++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
