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

    const int MOD = 1e9;
    int N, dp[100][10][1 << 10];
    cin >> N;
    for (int i = 1; i < 10; ++i) dp[0][i][1 << i] = 1;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < (1 << 10); ++k) {
                if (!dp[i][j][k]) continue;
                if (j > 0) {
                    int &n = dp[i + 1][j - 1][k | (1 << (j - 1))];
                    n = (n + dp[i][j][k]) % MOD;
                }
                if (j < 9) {
                    int &n = dp[i + 1][j + 1][k | (1 << (j + 1))];
                    n = (n + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) sum = (sum + dp[N - 1][i][(1 << 10) - 1]) % MOD;
    cout << sum << '\n';

    return 0;
}
