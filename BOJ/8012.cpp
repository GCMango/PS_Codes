#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = (int)floor(log2(30000));

int N, M;
vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;

void get_tree(int cur, int pnode) {
    for (int i = 1; i <= MAX_LVL; ++i)
        par[cur][i] = par[par[cur][i - 1]][i - 1];

    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        depth[next] = depth[cur] + 1;
        par[next][0] = cur;
        get_tree(next, cur);
    }
}

int get_lca(int cur, int next) {
    if (depth[cur] != depth[next]) {
        if (depth[cur] >= depth[next])
            swap(cur, next);
        for (int i = MAX_LVL; i >= 0; --i)
            if (depth[cur] <= depth[par[next][i]])
                next = par[next][i];
    }
    int lca = cur;
    if (cur != next) {
        for (int i = MAX_LVL; i >= 0; --i) {
            if (par[cur][i] != par[next][i]) {
                cur = par[cur][i];
                next = par[next][i];
            }
            lca = par[cur][i];
        }
    }
    return lca;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    par.resize(N + 1, vector<int>(MAX_LVL + 1));
    depth.resize(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    get_tree(1, 0);

    int cur = 1, sum = 0;
    cin >> M;
    while (M--) {
        int next;
        cin >> next;
        int lca = get_lca(cur, next);
        sum += (depth[cur] + depth[next]) - depth[lca] * 2;
        cur = next;
    }
    cout << sum << "\n";

    return 0;
}
