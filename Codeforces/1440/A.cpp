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

void solve() {
    int N, a, b, h;
    int sum = 0, cnta = 0, cntb = 0;
    cin >> N >> a >> b >> h;
    for (int i = 0; i < N; ++i) {
        char c; cin >> c;
        if (c == '0') cnta++;
        else cntb++;
    }
    cout << min(N * min(a, b) + (a > b ? cnta : cntb) * h, cnta * a + cntb * b) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

