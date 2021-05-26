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

typedef pair<pair<int, int>, int> piii;
const int MAX = 2000002;
int civil[2002][2002];

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

    int N, K;
    pii opt[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<piii> que;
    UnionFind uf;

    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        civil[a][b] = i + 1;
        que.push({{a, b}, 0});
    }

    int cnt = K - 1, ans, exc = 0;
    while (!que.empty()) {
        piii cur = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = cur.x.x + opt[i].x, y = cur.x.y + opt[i].y;
            int r = cur.y + 1, compa = civil[cur.x.x][cur.x.y], compb = civil[x][y];
            if (x < 1 || x > N || y < 1 || y > N || compa == compb) continue;
            if (compb && uf.merge(compa, compb)) {
                if (compa > compb && cnt == 1)
                    exc = 1;
                cnt--;
            }
            else if (!compb) {
                civil[x][y] = compa;
                que.push({{x, y}, r});
            }
        }
        if (cnt == 0) {
            ans = cur.y + exc;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}

/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 2 0 0 0 0 8 0 0
1 1 2 2 2 8 8 8 8 0
*/
