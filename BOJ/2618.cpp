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

int N, W, dp[1001][1001];
bool track[1001][1001];
pii evt[1001];

int dfs(int i, int j, int k) {
    if (i >= W || j >= W) return dp[i][j] = k;
    if (dp[i][j]) return dp[i][j] + k;

    pii cur_i = evt[i], cur_j = evt[j];
    if (!i) cur_i = {1, 1};
    if (!j) cur_j = {N, N};
    
    int next = max(i, j) + 1;
    int next_i = abs(cur_i.x - evt[next].x) + abs(cur_i.y - evt[next].y);
    int next_j = abs(cur_j.x - evt[next].x) + abs(cur_j.y - evt[next].y);

    int a = dfs(next, j, k + next_i);
    int b = dfs(i, next, k + next_j);

    dp[i][j] = min(a, b) - k;
    track[i][j] = a < b;

    return dp[i][j] + k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;
    for (int i = 1; i <= W; ++i) cin >> evt[i].x >> evt[i].y;
    cout << dfs(0, 0, 0) << '\n';

    int i = 0, j = 0;
    while (i < W && j < W) {
        int next = max(i, j) + 1;
        if (track[i][j])
            i = next;
        else
            j = next;
        cout << (i < j) + 1 << '\n';
    }

    return 0;
}

