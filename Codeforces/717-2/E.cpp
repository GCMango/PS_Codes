#include <bits/stdc++.h>
#define show(x) cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> Pairs;

const int N = 202020;

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
template<typename T>
inline void read(T &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

vector<int> G[N];
int col[N];
int n, x, y, gcnt;
vector<int> ans;

inline void AddEdge(int from, int to) {
    G[from].emplace_back(to);
    G[to].emplace_back(from);
}
inline void dfs(int u, int fa) {
    if (fa) col[u] ^= 1;
    ans.emplace_back(u);
    for (int to: G[u])
        if (to != fa) dfs(to, u);
    if (!col[u] && fa) {
        ans.emplace_back(fa);
        ans.emplace_back(u);
        col[u] ^= 1; col[fa] ^= 1;
    }
    if (fa) {
        ans.emplace_back(fa);
        col[fa] ^= 1;
    }
}

int main(void) {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x); col[i] = (x == 1);
    }
    for (int i = 1; i < n; i++) {
        read(x); read(y);
        AddEdge(x, y);
    }
    dfs(1, 0);
    if (!col[1]) {
        ans.emplace_back(*G[1].begin());
        ans.emplace_back(1);
        ans.emplace_back(*G[1].begin());
    }
    for (int x: ans) printf("%d ", x);
}
