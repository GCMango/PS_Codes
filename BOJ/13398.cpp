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

    int N, arr[100001], dp[100001][2];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int ans;
    ans = dp[0][0] = arr[0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max({ans, dp[i][0], dp[i][1]});
    }

    cout << ans << '\n';

    return 0;
}
