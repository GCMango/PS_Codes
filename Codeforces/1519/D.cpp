#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, sum = 0, mx = 0;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    for (ll i = 0; i < N; ++i) cin >> a[i];
    for (ll i = 0; i < N; ++i) cin >> b[i];
    for (ll i = 0; i < N; ++i) sum += a[i] * b[i];
    mx = sum;

    vector<vector<ll>> dp(N, vector<ll>(N));
    for (ll i = 0; i < N; ++i) dp[i][i] = sum;
    for (ll i = 0; i < N - 1; ++i) {
        ll n = sum;
        n -= a[i] * b[i] + a[i + 1] * b[i + 1];
        n += a[i + 1] * b[i] + a[i] * b[i + 1];
        dp[i][i + 1] = n;
        mx = max(mx, n);
    }

    for (ll len = 3; len <= N; ++len) {
        for (ll i = 0; i < N - len + 1; ++i) {
            ll n = dp[i + 1][i + len - 2];
            n -= a[i] * b[i] + a[i + len - 1] * b[i + len - 1];
            n += a[i] * b[i + len - 1] + a[i + len - 1] * b[i];
            dp[i][i + len - 1] = n;
            mx = max(mx, n);
        }
    }

    cout << mx << "\n";

    return 0;
}

