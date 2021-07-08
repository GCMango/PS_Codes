#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MXN = 20;
int N, arr[MXN][MXN], dp[MXN][1 << MXN], nxt[MXN][1 << MXN];

int dfs(int n, int chk) {
    if (chk == (1 << N) - 1) return 0;
    int &ret = dp[n][chk], &t = nxt[n][chk];
    if (ret != 1e9) return ret;
    for (int i = 0; i < N; ++i) {
        if (!(chk & (1 << i))) {
            int comp = dfs(n + 1, chk | (1 << i)) + arr[n + 1][i];
            if (ret > comp) {
                ret = comp;
                t = chk | (1 << i);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(&dp[0][0], &dp[MXN - 1][1 << MXN], 1e9);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    int ans = 1e9, cur = 0, res[MXN];
    for (int i = 0; i < N; ++i) {
        int comp = dfs(0, 1 << i) + arr[0][i];
        if (ans > comp) {
            ans = comp;
            cur = 1 << i;
        }
    }
    int pos = cur;
    for (int i = 0; i < N; ++i) {
        res[i] = __builtin_ctz(pos);
        pos = cur ^ nxt[i][cur];
        cur = nxt[i][cur];
    }
    cout << ans << '\n';
    for (int i = 0; i < N; ++i) cout << res[i] + 1 << ' ';
    cout << '\n';

    return 0;
}
