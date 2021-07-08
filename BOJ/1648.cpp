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

const int MXN = 11;
int N, M;
ll dp[MXN * MXN][1 << MXN];

ll dfs(int n, int chk) {
    if (n >= N * M) return !chk;
    ll &ret = dp[n][chk];
    if (ret != -1) return ret;
    ret = 0;
    if (chk & 1) ret += dfs(n + 1, chk >> 1);
    else {
        if (n % M != (M - 1) && !(chk & (1 << 1)))
            ret += dfs(n + 2, chk >> 2);
        ret += dfs(n + 1, (chk >> 1) | (1 << (M - 1)));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    if (N % 2 && M % 2) { cout << "0\n"; return 0; }
    cout << dfs(0, 0) << '\n';

    return 0;
}
