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
    int N, sum = 0, dp[100][10];
    cin >> N;
    for (int i = 1; i < 10; ++i) dp[0][i] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j > 0) { dp[i][j] += dp[i][j - 1]; dp[i][j] %= MOD; }
            if (j < N - 1) { dp[i][j] += dp[i - 1][j + 1]; dp[i][j] %= MOD; }
        }
    }
    for (int i = 0; i < 10; ++i) {
        sum += dp[N - 1][i];
        sum %= MOD;
    }
    cout << sum << '\n';

    return 0;
}
