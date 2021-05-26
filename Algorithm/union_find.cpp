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

const int MAX = 100001;

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



    return 0;
}

