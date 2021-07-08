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

const int MXN = 16, MOD = 10000;
int N, arr[MXN][MXN], dp[MXN][1 << MXN];

int dfs(int n, int chk) {
    if (chk == (1 << N) - 1) return 1;
    int &ret = dp[n][chk];
    if (ret) return ret;
    for (int i = 0; i < N; ++i)
        if (!(chk & (1 << i)))
            ret = (ret + dfs(n + 1, chk | (1 << i)) * arr[n + 1][i]) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    int sum = 0;
    for (int i = 0; i < N; ++i) sum = (sum + dfs(0, 1 << i) * arr[0][i]) % MOD;
    cout << sum << '\n';

    return 0;
}
