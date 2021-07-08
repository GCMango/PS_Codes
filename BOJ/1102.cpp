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

const int MXN = 16;
int N, P, arr[MXN][MXN], dp[1 << MXN];
string s;

int dfs(int chk) {
    if (__builtin_popcount(chk) >= P) return 0;
    int &ret = dp[chk];
    if (ret != 1e9) return ret;
    for (int i = 0; i < N; ++i)
        if (chk & (1 << i))
            for (int j = 0; j < N; ++j)
                if (!(chk & (1 << j)))
                    ret = min(ret, dfs(chk | (1 << j)) + arr[i][j]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dp, dp + (1 << MXN), 1e9);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    cin >> s >> P;
    int cur = 0;
    for (int i = 0; i < N; ++i)
        if (s[i] == 'Y')
            cur |= 1 << i;
    int ans = dfs(cur);
    cout << (ans == 1e9 ? -1 : ans) << '\n';

    return 0;
}
