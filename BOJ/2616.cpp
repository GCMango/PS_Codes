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

    int N, M;
    cin >> N;
    vector<int> input(N + 1);
    vector<int> sum(N + 1, 0);
    vector<vector<int>> dp(4, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        cin >> input[i];
        sum[i] = sum[i - 1] + input[i];
    }

    cin >> M;
    for (int i = 1; i <= 3; ++i)
        for (int j = M * i; j <= N; ++j)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + sum[j] - sum[j - M]);

    cout << dp[3][N] << '\n';

    return 0;
}
