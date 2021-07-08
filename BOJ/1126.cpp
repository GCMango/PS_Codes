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

    const int MXM = 500000;
    int N, dp[2][MXM + 1];
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int hgt, n = i % 2;
        cin >> hgt;
        fill(dp[n], dp[n] + MXM, -1);
        if (dp[!n][0] == -1) dp[!n][0] = 0;
        for (int j = 0; j <= MXM; ++j) {
            dp[n][j] = dp[!n][j];
            if (j + hgt <= MXM && dp[!n][j + hgt] != -1)
                dp[n][j] = max(dp[n][j], dp[!n][j + hgt] + hgt);
            if (j - hgt >= 0 && dp[!n][j - hgt] != -1)
                dp[n][j] = max(dp[n][j], dp[!n][j - hgt]);
            if (hgt - j >= 0 && dp[!n][hgt - j] != -1)
                dp[n][j] = max(dp[n][j], dp[!n][hgt - j] + hgt - j);
        }
    }
    if (!dp[N % 2][0]) cout << "-1\n";
    else cout << dp[N % 2][0] << '\n';

    return 0;
}
