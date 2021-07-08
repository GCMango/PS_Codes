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

int N, M;
vector<pii> g[2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            int a, b, n; cin >> a >> b >> n;
            g[a].push_back({b, n});
            g[b].push_back({a, n});
        }
    }

    return 0;
}
