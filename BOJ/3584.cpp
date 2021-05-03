#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = 30;

int N, root;
vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;

void find_root(int cur) {
    if (par[cur][0] == 0) {
        root = cur;
        return;
    }
    find_root(par[cur][0]);
}

void solve(int cur, int pnode) {
    depth[cur] = depth[pnode] + 1;
    par[cur][0] = pnode;

    for (int i = 1; i <= MAX_LVL; ++i)
        par[cur][i] = par[par[cur][i - 1]][i - 1];

    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (next != pnode)
            solve(next, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int pnt;
        cin >> N;
        graph.clear();
        graph.resize(N + 1);
        par.clear();
        par.resize(N + 1, vector<int>(MAX_LVL + 1, 0));
        depth.clear();
        depth.resize(N + 1, 0);
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            pnt = a;
            cin >> a >> b;
            graph[a].push_back(b);
            par[b][0] = a;
        }

        find_root(pnt);
        solve(root, 0);

        int a, b;
        cin >> a >> b;
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b])
                swap(a, b);
            for (int i = MAX_LVL; i >= 0; --i)
                if (depth[a] <= depth[par[b][i]])
                    b = par[b][i];
        }

        int lca = a;
        if (a != b) {
            for (int i = MAX_LVL; i >= 0; --i) {
                if (par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
                lca = par[a][i];
            }
        }

        cout << lca << "\n";
    }

    return 0;
}
