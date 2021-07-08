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

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        ll N, a, b, cnt = 0;
        vector<int> v;
        cin >> a >> b >> N;
        for (ll i = 2; i * i <= N; ++i)
            if (N % i == 0)
                v.push_back(i), v.push_back(N / i);
        sort(all(v)), v.erase(unique(all(v)), v.end());
        ll s = lower_bound(all(v), a) - v.begin();
        ll e = upper_bound(all(v), b) - v.begin() - 1;
        cout << "Case #" << tc << ": " << (b - a + 1 - (e - s + 1)) << '\n';
    }

    return 0;
}
