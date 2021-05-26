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

const int MAX = 200002;

struct UnionFind {
    int uf[MAX];
    UnionFind() { fill(uf, uf + MAX, -1); }
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, par[MAX], qry[MAX * 2][3];
    UnionFind uf;
    cin >> N >> Q;
    for (int i = 2; i <= N; ++i)
        cin >> par[i];
    Q += N - 1;
    for (int i = 0; i < Q; ++i) {
        cin >> qry[i][0];
        if (qry[i][0] == 0)
            cin >> qry[i][1];
        else
            cin >> qry[i][1] >> qry[i][2];
    }
    stack<int> ans;
    for (int i = Q - 1; i >= 0; --i) {
        if (qry[i][0] == 0) uf.merge(qry[i][1], par[qry[i][1]]);
        else {
            int u = uf.find(qry[i][1]), v = uf.find(qry[i][2]);
            ans.push(u == v);
        }
    }
    while (!ans.empty()) {
        cout << (ans.top() ? "YES" : "NO") << '\n';
        ans.pop();
    }

    return 0;
}
