#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

const int MOD = 1e9 + 3;
int N, K, sum = 0, dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) dp[i][1] = i;
    for (int i = 4; i <= N; ++i) {
        for (int j = 2; j <= K; ++j) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[N][K];

    return 0;
}

/*
    1 2 3 4 5 6 7  8  9
    0 0 0 2 5 9 14 20 
    0 0 0 0 0 2 7  16
    0 0 0 0 0 0 0  2
 */
