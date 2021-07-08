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

    int T;
    cin >> T;
    while (T--) {
        ll N, arr[100000], sum[100000];
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> arr[i];
        sort(arr, arr + N);
        for (int i = 1; i < N; ++i) sum[i] = arr[i] + sum[i - 1];
        ll ans = arr[N - 1];
        for (int i = 1; i < N; ++i) ans -= arr[i] * i - sum[i - 1];
        cout << ans << '\n';
    }

    return 0;
}
