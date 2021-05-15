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

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> input(N + 1);
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1e9));
        vector<int> sum(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            cin >> input[i];
            sum[i] = sum[i - 1] + input[i];
            dp[i][i] = 0;
        }

        for (int len = 1; len <= N; ++len) {
            for (int i = 1; i <= N - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }

        cout << dp[1][N] << '\n';
    }

    return 0;
}
