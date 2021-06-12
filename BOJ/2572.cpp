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

typedef pair<int, char> pic;
const int MXN = 1000;
const int MXM = 500;

int N, M, K, dp[MXM + 1][MXN + 1];
char arr[MXN + 1];
vector<vector<pic>> graph;

int dfs(int cur, int cnt) {
    if (cnt > N) return 0;
    if (dp[cur][cnt] != -1) return dp[cur][cnt];
    int mx = 0;
    for (auto next : graph[cur])
        mx = max(mx, dfs(next.x, cnt + 1) + (next.y == arr[cnt] ? 10 : 0));
    return dp[cur][cnt] = mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    cin >> M >> K;
    graph.resize(M + 1);
    for (int i = 0; i < K; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cout << dfs(1, 1) << '\n';

    return 0;
}
