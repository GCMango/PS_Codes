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

    int N, mx[2][3], mn[2][3]; cin >> N;
    memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
    for (int i = 0; i < N; ++i) {
        int n = i % 2;
        int a, b, c; cin >> a >> b >> c;
        mx[n][0] = max(mx[!n][0], mx[!n][1]) + a;
        mx[n][1] = max({mx[!n][0], mx[!n][1], mx[!n][2]}) + b;
        mx[n][2] = max(mx[!n][1], mx[!n][2]) + c;
        mn[n][0] = min(mn[!n][0], mn[!n][1]) + a;
        mn[n][1] = min({mn[!n][0], mn[!n][1], mn[!n][2]}) + b;
        mn[n][2] = min(mn[!n][1], mn[!n][2]) + c;
    }
    int n = (N - 1) % 2;
    cout << max({mx[n][0], mx[n][1], mx[n][2]}) << ' ' << min({mn[n][0], mn[n][1], mn[n][2]}) << '\n';

    return 0;
}

