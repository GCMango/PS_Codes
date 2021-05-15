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

const int MAX_LVL = 32 - __builtin_clz(100000);

int N, M;
vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;
vector<pii> range;
vector<pii> tree;

void init_tree(int cur, int pnode) {
    for (int i = 1; i <= MAX_LVL; ++i)
        par[cur][i] = par[par[cur][i - 1]][i - 1];
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        depth[next] = depth[cur] + 1;
        par[next][0] = cur;
        init_tree(next, cur);
    }
}

void update_tree(int cur, int pnode, int n) {
    cout << cur << "\n";
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        plant[next] += n;
        update_tree(next, cur, n);
    }
}

int get_lca(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] >= depth[b])
            swap(a, b);
        for (int i = MAX_LVL; i >= 0; --i)
            if (depth[a] <= depth[par[b][i]] && par[b][i] != 0)
                b = par[b][i];
    }
    int lca = a;
    if (a != b) {
        for (int i = MAX_LVL; i >= 0; --i) {
            if (par[a][i] != par[b][i] && par[a][i] != 0 && par[b][i] != 0) {
                a = par[a][i];
                b = par[b][i];
            }
            lca = par[a][i];
        }
    }
    return lca;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    par.resize(N + 1, vector<int>(MAX_LVL + 1));
    depth.resize(N + 1);
    range.resize(N + 1);
    tree.resize(N * 4, {0, 0});

    for (int i = 0 ; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    init_tree(1, 0);

    while (M--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        int lca = get_lca(a, b);
        if (c == 'P') {
            //cout << lca << ' ';
            int aa, bb;
            int ans_a = depth[a] - depth[lca], ans_b = depth[b] - depth[lca];
            for (int i = ans_a; i > 0; --i) {
                plant[a] += i;
                if (par[a][0] == lca)
                    aa = a;
                a = par[a][0];
            }
            for (int i = ans_b; i > 0; i--) {
                plant[b] += i;
                if (par[b][0] == lca)
                    bb = b;
                b = par[b][0];
            }
            update_tree(lca, a, b, i - 1);
            //cout << plant[aa] << ' ' << plant[bb] << "\n";
        }
        else
            cout << (plant[a] + plant[b]) - plant[lca] * 2 << "\n";
    }

    return 0;
}
