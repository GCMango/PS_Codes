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
 
const int MXN = 2002;
int N, a = 0, b = 0, arr[MXN], dp[MXN][MXN];
 
int dfs(int i, int j) {
    if (i >= N || j >= N) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int next = max(i, j) + 1, tmp = a, res;
    a = arr[next];
    res = dfs(next, j) + (i ? abs(tmp - arr[next]) : 0);
    a = tmp, tmp = b, b = arr[next];
    res = min(res, dfs(i, next) + (j ? abs(tmp - arr[next]) : 0));
    b = tmp;
    return dp[i][j] = res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';
 
    return 0;
}
