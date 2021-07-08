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
    int N, arr[200000], ans[200000]; cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    int n = 0;
    for (int i = 0; i < N - 1; ++i)
        if (arr[i + 1] - arr[i] < arr[n + 1] - arr[n])
            n = i;
    ans[0] = arr[n], ans[N - 1] = arr[n + 1];
    for (int i = n - 1; i >= 0; --i)
        ans[N + i - n - 1] = arr[i];
    for (int i = n + 2; i < N; ++i)
        ans[i - n - 1] = arr[i];
    for (int i = 0; i < N; ++i) cout << ans[i] << ' ';
    cout << '\n';
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
