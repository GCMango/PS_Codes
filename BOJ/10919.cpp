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
    
const int MXN = 1e7;
int N, K, L;
ll a[MXN], b[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> L;
    int cnta = 0, cntb = 0;
    for (int i = 0; i < N; ++i) {
        int n; cin >> n;
        if (!n) continue;
        if (n <= L / 2) {
            a[cnta] = n;
            cnta++;
        }
        else {
            b[cntb] = L - n;
            cntb++;
        }
    }

    reverse(b, b + cntb);
    for (int i = 0; i < K && i < cnta; ++i) a[i] *= 2;
    for (int i = 0; i < K && i < cntb; ++i) b[i] *= 2;
    for (int i = K; i < cnta; ++i) a[i] = a[i - K] + a[i] * 2;
    for (int i = K; i < cntb; ++i) b[i] = b[i - K] + b[i] * 2;

    ll ans = (!cnta ? 0 : a[cnta - 1]) + (!cntb ? 0 : b[cntb - 1]);
    for (int i = 0; i <= K; ++i) {
        ll l = i >= cnta ? 0 : a[cnta - i - 1];
        ll r = K - i >= cntb ? 0 : b[cntb - K + i - 1];
        ans = min(ans, l + r + L);
    }

    cout << ans << '\n';

    return 0;
}
