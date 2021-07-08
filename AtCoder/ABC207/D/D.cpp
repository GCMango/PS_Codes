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

    const double rad_to_deg = 180 / M_PI, deg_to_rad = M_PI / 180;
    int N;
    bool flag = 0;
    double dist[100], deg[100];
    pii a[100], b[100];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i].x >> a[i].y;
        dist[i] = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
        deg[i] = atan2(a[i].y, a[i].x) * rad_to_deg;
    }
    for (int i = 0; i < N; ++i) cin >> b[i].x >> b[i].y;
    sort(a, a + N), sort(b, b + N);

    for (double i = 1; i <= 12; ++i) {
        cerr << i << '\n';
        bool flag2 = 1;
        for (int j = 0; j < N; ++j) {
            deg[j] -= 30;
            if (deg[j] <= -180) deg[j] = 360 - deg[j];
            a[j].x = dist[j] * cos(deg[j] * deg_to_rad);
            a[j].y = dist[j] * sin(deg[j] * deg_to_rad);
            cerr << a[j].x << ' ' << a[j].y << '\n';
        }
        sort(a, a + N);
        pii diff = { abs(a[0].x - b[0].x), abs(a[0].y - b[0].y) };
        for (int j = 1; j < N; ++j)
            if (abs(a[j].x - b[j].x) != diff.x || abs(a[j].y - b[j].y) != diff.y)
                flag2 = 0;
        flag |= flag2;
        if (flag) break;
    }

    cout << (flag ? "Yes" : "No") << '\n';

    return 0;
}

