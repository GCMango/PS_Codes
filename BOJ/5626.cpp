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

    int N, M, arr[10001], dp[2][5005];
    const int MOD = 1e9 + 7;
    cin >> N;
    M = N / 2;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if (arr[i] > min(i - 1, N - i)) {
            cout << "0\n";
            return 0;
        }
    }

    dp[1][0] = 1;
    for (int i = 2; i <= N; ++i) {
        int a = i % 2;
        int b = (i - 1) % 2;
        for (int j = 0; j <= M; ++j) dp[a][j] = 0;
        if (arr[i] == -1) {
            for (int j = 0; j <= M; ++j) {
                if (j > min(i - 1, N - i)) break;
                dp[a][j] += dp[b][j];
                dp[a][j] %= MOD;
                if (j > 0) {
                    dp[a][j] += dp[b][j - 1];
                    dp[a][j] %= MOD;
                }
                if (j < M)
                    dp[a][j] += dp[b][j + 1];
                dp[a][j] %= MOD;
            }
        }
        else {
            int j = arr[i];
            dp[a][j] += dp[b][j];
            dp[a][j] %= MOD;
            if (j > 0) {
                dp[a][j] += dp[b][j - 1];
                dp[a][j] %= MOD;
            }
            if (j < M)
                dp[a][j] += dp[b][j + 1];
            dp[a][j] %= MOD;
        }
    }

    cout << dp[N % 2][0] << '\n';

    return 0;
}
