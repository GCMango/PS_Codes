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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1e9 + 7;
    vector<ll> lcm{1};
    while (lcm.back() <= 1e16)
        lcm.push_back(lcm.size() / gcd(lcm.size(), lcm.back()) * lcm.back());
    lcm.push_back(lcm.size() / gcd(lcm.size(), lcm.back()) * lcm.back());
    int T; cin >> T;
    while (T--) {
        ll N; cin >> N;
        ll ans = 0, tmp = 0;
        for (int i = lcm.size() - 1; i > 0; --i) {
            ans += (i + 1) * (N / lcm[i] - tmp);
            tmp = N / lcm[i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}
