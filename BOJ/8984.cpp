#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end());
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    ll dp[100000][2];
    pll p[100000];
    cin >> N >> L;
    vector<ll> arrx, arry;

    for (int i = 0; i < N; ++i) {
        cin >> p[i].x >> p[i].y;
        arrx.push_back(p[i].x);
        arry.push_back(p[i].y);
    }

    sort(p, p + N);
    compress(arrx); compress(arry);

    ll mx = 0;
    for (int i = 0; i < N; ++i) {
        ll x = lower_bound(all(arrx), p[i].x) - arrx.begin();
        ll y = lower_bound(all(arry), p[i].y) - arry.begin();
        ll val_x = dp[x][0], val_y = dp[y][1];
        ll dist = abs(p[i].x - p[i].y) + L;
        dp[x][0] = max(dp[x][0], val_y + dist);
        dp[y][1] = max(dp[y][1], val_x + dist);
        mx = max({mx, dp[x][0], dp[y][1]});
    }

    cout << mx << '\n';

    return 0;
}
