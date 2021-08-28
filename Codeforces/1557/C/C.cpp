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

    const int MOD = (int)1e9 + 7;
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        if (!K) { cout << "1\n"; continue; }
        ll odd_cnt = 1, even_cnt;
        for (int i = 0; i < N - 1; ++i)
            odd_cnt = (odd_cnt * 2) % MOD;
        even_cnt = odd_cnt;
        if (N % 2) odd_cnt--, even_cnt++;

        odd_cnt %= MOD, even_cnt %= MOD;

        vector<vector<ll>> dp(K, vector<ll>(2));
        dp[0][0] = even_cnt, dp[0][1] = odd_cnt;
        for (int i = 1; i < K; ++i) {
            dp[i][0] = (dp[i - 1][0] * even_cnt) % MOD;
            dp[i][1] = ((((dp[i - 1][0] + dp[i - 1][1]) % MOD * odd_cnt) % MOD) + (dp[i - 1][1] * (even_cnt - 1)) % MOD) % MOD;
            if (N % 2 == 0) dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
            else dp[i][1] += dp[i - 1][1];
        }

        cout << dp[K - 1][0] << '\n';
    }

    return 0;
}
