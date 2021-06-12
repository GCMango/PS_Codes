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

const int MXN = 50005;

struct UnionFind {
    int uf[MXN];
    UnionFind() { memset(uf, -1, sizeof(uf)); }
    int find(int a) {
        if (uf[a] < 0) return a;
        return uf[a] = find(uf[a]);
    }
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        uf[b] = a;
        return true;
    }
};

struct Edge {
    int s;
    int e;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    int sum = 0;
    Edge edge[200002];
    UnionFind uf;
    vector<int> nums;

    for (int i = 0; i < E; ++i)
        cin >> edge[i].s >> edge[i].e >> edge[i].n;

    sort(edge, edge + E, [&](Edge &a, Edge &b) { return a.n < b.n; });

    for (int i = 0; i < E; ++i) {
        if (uf.merge(edge[i].s, edge[i].e)) {
            sum += edge[i].n;
            nums.push_back(i);
        }
    }

    cout << sum << '\n';

    for (int i = 0; i < nums.size(); ++i) cout << edge[nums[i]].s << ' ' << edge[nums[i]].e << ' ' << edge[nums[i]].n << '\n';

    return 0;
}
