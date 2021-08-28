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

    cout << fixed << setprecision(9);
    cerr << fixed << setprecision(9);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<double> arr(N), a(N), b(N);
        for (auto &i : arr) cin >> i;
        double ans = -1.0e18;

        sort(all(arr));
        
        a[0] = arr[0], b[N - 1] = arr[N - 1];
        for (int i = 1; i < N; ++i)
            a[i] = a[i - 1] + arr[i];
        for (int i = N - 2; i >= 0; --i)
            b[i] = b[i + 1] + arr[i];

        for (int i = 1; i < N; ++i) {
            double aa = a[i - 1] / i, bb = b[i] / (N - i);
            ans = max(ans, aa + bb);
        }

        cout << ans << '\n';
    }

    return 0;
}

