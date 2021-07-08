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

const int MXN = 5005;
string a, b;
int dp[MXN][MXN];
bitset<26> bita[MXN], bitb[MXN];

int dfs(int u, int v, bitset<26> bit) {
    if (u == a.size() && v == b.size()) return 0;
    int &ret = dp[u][v];
    if (ret != -1) return ret;
    ret = 1e9;
    if (u < a.size()) {
        bitset<26> tmp(bit);
        bit.set((int)a[u] - 65, 1);
        bit &= (bita[u + 1] | bitb[v]);
        ret = min(ret, (int)(dfs(u + 1, v, bit) + bit.count()));
        bit = tmp;
    }
    if (v < b.size()) {
        bitset<26> tmp(bit);
        bit.set((int)b[v] - 65, 1);
        bit &= (bita[u] | bitb[v + 1]);
        ret = min(ret, (int)(dfs(u, v + 1, bit) + bit.count()));
        bit = tmp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < MXN; ++i) { bita[i].reset(); bitb[i].reset(); }
        cin >> a >> b;
        for (int i = a.size() - 1; i >= 0; --i) {
            bita[i] |= bita[i + 1];
            bita[i].set((int)a[i] - 65, 1);
        }
        for (int i = b.size() - 1; i >= 0; --i) {
            bitb[i] |= bitb[i + 1];
            bitb[i].set((int)b[i] - 65, 1);
        }
        cout << dfs(0, 0, {}) << '\n';
    }

    return 0;
}

