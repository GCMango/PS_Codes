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

int N;
ll mx = 0, wgt[200002], dp[200002][2];
vector<vector<int>> graph;

void dfs(int cur) {
    ll a = 0, b = 0;
    dp[cur][0] = wgt[cur];
    for (auto next : graph[cur]) {
        dfs(next);
        dp[cur][0] = max(dp[cur][0], dp[cur][0] + dp[next][0]);
        dp[cur][1] = max(dp[cur][1], dp[cur][1] + )
        if (dp[next][0] > a) {
            b = a;
            a = dp[next][0];
        }
        else if (dp[next][0] > b) b = dp[next][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);

    int root = 1;
    for (int i = 1; i <= N; ++i) {
        cin >> wgt[i];
        int n;
        cin >> n;
        if (n == -1) {
            root = i;
            continue;
        }
        graph[n].push_back(i);
    }
    
    dfs(root);
    cout << mx << '\n';

    return 0;
}
