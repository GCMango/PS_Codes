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
    ll N, x, t; cin >> N >> x >> t;
    ll r = (t / x);
    ll ans = r * max(0LL, N - r), n;
    if (N < r) n = N - 1;
    else n = N - (N - r) - 1;
    n = (n * (n + 1)) / 2;
    cout << ans + n << '\n';
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
