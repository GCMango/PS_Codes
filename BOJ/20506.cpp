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

int N;
vector<vector<int>> graph;
ll cnt[200001], dp[200001][2], sum_a = 0, sum_b = 0;

void solve(int cur, int pnode) {
    cnt[cur] = 1;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        cnt[cur] += cnt[next];
        dp[cur][0] -= dp[next][1];
    }
    dp[cur][0] += cnt[cur] * cnt[cur];
    dp[cur][1] += cnt[cur] * cnt[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int root;
    cin >> N;
    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;
        if (n == 0) root = i;
        graph[n].push_back(i);
    }

    solve(root, 0);

    int idx = 0, cur = 0;
    for (int i = 1; i <= N; ++i) {
        ll a = dp[i][0] - (dp[i][0] / 2), b = dp[i][0] / 2;
        a *= i, b *= i;
        if (!idx) {
            sum_a += a;
            sum_b += b;
        }
        else {
            sum_a += b;
            sum_b += a;
        }
        cur += dp[i][0];
        idx = cur % 2;
    }
    
    cout << sum_b << ' ' << sum_a << '\n';

    return 0;
}
