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
  
const int MXN = 15, MXC = 50;
int N, C, arr[MXN], cost[MXC], dp[MXC][1 << MXN];
  
int dfs(int n, int c, int chk) {
    if (chk == (1 << N) - 1) return cost[c];
    int &ret = dp[c][chk];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < N; ++i) {
        if (!(chk & (1 << i))) {
            int sost = min(C, c + arr[i]), iost = max(0, arr[i] - (C - c)), nost = max(0, c - (C - arr[i])), ichk = chk | (1 << i);
            ret = max({ ret, dfs(i, sost, ichk) + cost[nost], dfs(i, iost, ichk) + cost[sost], dfs(i, arr[i], ichk) + cost[c]});
        }
    }
    return ret;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  
    memset(dp, -1, sizeof(dp));
    cin >> N >> C;
    //cin >> C >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i <= C; ++i) cin >> cost[i];
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans = max(ans, dfs(i, arr[i], 1 << i));
    cout << ans << '\n';
  
    return 0;
}
