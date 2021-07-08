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
        int N, M; cin >> N >> M;
        ll dp[2001][11]; memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= M; ++i) dp[i][1] = 1;
        for (int i = 2; i <= M; ++i)
            for (int j = 2; j <= N; ++j)
                for (int k = 1; k <= i / 2; ++k)
                    dp[i][j] += dp[k][j - 1];
        ll sum = 0;
        for (int i = 1; i <= M; ++i) sum += dp[i][N];
        cout << sum << '\n';
    }

    return 0;
}
