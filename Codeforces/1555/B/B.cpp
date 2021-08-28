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
    cout << fixed << setprecision(6);

    int T; cin >> T;
    while (T--) {
        double W, H; cin >> W >> H;
        double x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        double w, h; cin >> w >> h;
        double ww = abs(x1 - x2), hh = abs(y1 - y2);
        double ans = 1.0e18;
        if (abs(x2 - x1) + w > W && abs(y2 - y1) + h > H) { cout << "-1\n"; continue; }
        if (x1 >= w || y1 >= h || x2 <= W - w || y2 <= H - h) ans = 0;
        if (ww + w <= W) ans = min({ans, abs(x1 - w), abs(x2 - (W - w))});
        if (hh + h <= H) ans = min({ans, abs(y1 - h), abs(y2 - (H - h))});
        cout << ans << '\n';
    }

    return 0;
}
