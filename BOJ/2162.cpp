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

const int MAX = 3000;

struct INFO {
    int x, y;
    int p, q;
    INFO (int xx = 0, int yy = 0, int pp = 0, int qq = 0) : x(xx), y(yy), p(pp), q(qq) {}
};

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

int ccw(pii &a, pii &b, pii &c) {
    int first = (b.x - a.x) * (c.y - a.y);
    int second = (b.y - a.y) * (c.x - a.x);
    int ans = first - second;
    if (ans < 0) return -1;
    if (ans > 0) return 1;
    return 0;
}

bool is_intersect(pii a, pii b, pii c, pii d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int N, arr[MAX];
INFO info[MAX];
UnionFind uf;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int cnt = N, mx = 0;
    for (int i = 0; i < N; ++i)
        cin >> info[i].x >> info[i].y >> info[i].p >> info[i].q;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            pii a = {info[i].x, info[i].y}, b = {info[i].p, info[i].q};
            pii c = {info[j].x, info[j].y}, d = {info[j].p, info[j].q};
            if (is_intersect(a, b, c, d) && uf.merge(i, j))
                cnt--;
        }
    }
    for (int i = 0; i < N; ++i) {
        int f = uf.find(i);
        arr[f]++;
        mx = max(mx, arr[f]);
    }
    cout << cnt << '\n' << mx << '\n';

    return 0;
}
