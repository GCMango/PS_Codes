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
    int N;
    string s;
    cin >> N >> s;
    vector<bool> checked(26, false);

    checked[(int)s[0] - 65] = true;
    for (int i = 1; i < s.size(); ++i) {
        if (checked[(int)s[i] - 65] && s[i] != s[i - 1]) {
            cout << "NO\n";
            return;
        }
        checked[(int)s[i] - 65] = true;
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
