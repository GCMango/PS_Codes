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

struct Edge {
    int start;
    int fin;
    int len;
};

int N, M, sum = 0, uf[10001];
Edge edges[100001];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> edges[i].start >> edges[i].fin >> edges[i].len;
    sort(edges, edges + M, [&](Edge &a, Edge &b) {
        return a.len < b.len;
    });
    fill(uf, uf + N, -1);
    for (int i = 0; i < M; ++i)
        if (merge(edges[i].start, edges[i].fin))
            sum += edges[i].len;
    cout << sum << '\n';

    return 0;
}
