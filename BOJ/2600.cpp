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

int v[3], dp[505][505][2];

bool dfs(int i, int j, int k) {
    if (dp[i][j][k] != -1) return dp[i][j][k];
    bool win = !k;
    for (int idx = 0; idx < 3; ++idx) {
        int a = !k, b = !k;
        if (i >= v[idx])
            a = dfs(i - v[idx], j, !k);
        if (j >= v[idx])
            b = dfs(i, j - v[idx], !k);
        if (a == k || b == k)
            win = k;
    }
    return dp[i][j][k] = win;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v[0] >> v[1] >> v[2];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 5; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (dfs(a, b, 1) ? 'A' : 'B') << '\n';
    }

    return 0;
}
