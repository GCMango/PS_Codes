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

    int N, M, arr[31];
    bool dp[31][88888];
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    dp[0][40000] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= 80000; ++j) {
            dp[i][j] = (dp[i - 1][j] | dp[i - 1][j + arr[i]]);
            if (j >= arr[i]) dp[i][j] |= dp[i - 1][j - arr[i]];
        }
    }
    cin >> M;
    while (M--) {
        int n; cin >> n;
        cout << (dp[N][n + 40000] ? "Y" : "N") << ' ';
    }
    cout << '\n';

    return 0;
}
