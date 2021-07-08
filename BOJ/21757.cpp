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

    int N; cin >> N;
    ll sum[100001], dp[100001][4];
    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        sum[i] = sum[i - 1] + n;
    }
    if (sum[N] % 4) { cout << "0\n"; return 0; }
    ll ans_sum = sum[N] / 4;
    for (int i = 1; i <= N; ++i) {
        dp[i - 1][0] = 1;
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (sum[i] == ans_sum * j) dp[i][j] += dp[i - 1][j - 1];
        }
    }
    cout << dp[N - 1][3] << '\n';

    return 0;
}
