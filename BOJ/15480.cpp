#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = (int)floor(log2(100000));

int N, M, max_depth = 0;
vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;

void solve(int cur, int pnode) {
    max_depth = max(max_depth, depth[cur]);
    for (int i = 1; i <= MAX_LVL; ++i)
        par[cur][i] = par[par[cur][i - 1]][i - 1];
    for (auto next : graph[cur]) {
        if (next != pnode) {
            depth[next] = depth[cur] + 1;
            par[next][0] = cur;
            solve(next, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    par.resize(N + 1, vector<int>(MAX_LVL + 1));
    depth.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    cin >> M;
    while (M--) {
        int r, u, v;
        cin >> r >> u >> v;
        int lvl = (int)floor(log2(max_depth - depth[r] + 1));
        if (depth[u] != depth[v]) {
            if (depth[u] >= depth[v])
                swap(u, v);
            for (int i = lvl; i >= 0; --i)
                if (depth[u] <= depth[par[v][i]])
                    v = par[v][i];
        }
        int lca = u;
        if (u != v) {
            for (int i = lvl; i >= 0; i--) {
                if (par[u][i] != par[v][i]) {
                    u = par[u][i];
                    v = par[v][i];
                }
                lca = par[u][i];
            }
        }
        cout << lca << "\n";
    }

    return 0;
}
