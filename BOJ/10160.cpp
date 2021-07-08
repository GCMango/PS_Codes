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

    const ll MOD = 1e9 + 9;
    int N, K; cin >> N >> K;
    ll dp[2][7] = {0, }; dp[1][0] = 1;
    for (int i = 0; i < N; ++i) {
        int n = i % 2;
        dp[n][0] = dp[!n][0] * (K - 1);
        for (int j = 1; j < 7; ++j)
            dp[n][0] += dp[!n][j] * (K - 2);
        dp[n][1] = dp[!n][0] + dp[!n][1] + dp[!n][3] + dp[!n][4] + dp[!n][5];
        for (int j = 2; j < 7; ++j)
            dp[n][j] = (j == 5 ? dp[!n][2] + dp[!n][6] : dp[!n][j - 1]);
        for (int j = 0; j < 7; ++j) dp[n][j] %= MOD;
    }
    ll ans = 0;
    for (int i = 0; i < 7; ++i)
        ans = (ans + dp[(N - 1) % 2][i]) % MOD;
    cout << ans << '\n';

    return 0;
}
