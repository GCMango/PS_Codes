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

    int T; cin >> T;
    while (T--) {
        int N, M, arr[501], dp[2][100000]; cin >> N >> M;
        for (int i = 1; i <= N; ++i) cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            int n = i % 2;
            for (int j = 0; j < M; ++j) dp[n][j] = -1;
            for (int j = 0; j < M; ++j) {
                if (dp[!n][j] == -1) continue;
                int next = (j + arr[i]) % M;
                dp[n][j] = max(dp[n][j], dp[!n][j]);
                dp[n][next] = max(dp[n][next], dp[!n][j] + 1);
            }
        }
        cout << dp[N % 2][0] << '\n';
    }

    return 0;
}
