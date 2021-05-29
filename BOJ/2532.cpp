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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    pii pos[500005];
    vector<int> L;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n, a, b;
        cin >> n >> a >> b;
        pos[n] = {a, b};
    }

    sort(all(pos), [&](pii &a, pii &b) {
        return a.x < b.x || (a.x == b.x && a.y > b.y);
    });

    L.push_back(abs(pos[0].x - pos[0].y));
    for (int i = 1; i < N; ++i) {

    }

    return 0;
}
