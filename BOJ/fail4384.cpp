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

int N, a, b, mn = 1e9, sum = 0;
int wgt[100], dp[100][100];

int dfs(int n, int r, int k) {
    if (dp[r][N / 2 - k]) return dp[r][N / 2 - k];

    if (k == N / 2) {
        if (abs(sum - n * 2) < mn) {
            mn = abs(sum - n * 2);
            a = n;
            b = abs(sum - n);
        }
        return;
    }

    for (int i = r + 1; i < N; ++i)
        dfs(n + wgt[i], i, k + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) { cin >> wgt[i]; sum += wgt[i]; }
    for (int i = N - 2; i >= 0; --i) sum[i] = wgt[i] + sum[i + 1];
    int result = dfs(0, -1, 0);

    return 0;
}
