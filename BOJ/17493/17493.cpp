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

int N, M;
vector<int> g[200000], dp[200000];

void dfs(int cur, int pnode) {
    for (auto &i : g[cur]) {
        if (i == pnode) continue;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        dp[a].push_back(0);
        dp[b].push_back(0);
    }
    dfs(1, 0);

    return 0;
}
