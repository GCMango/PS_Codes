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
    int N, a = 0, b = 0, arr[100];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[a] > arr[i]) a = i;
        if (arr[b] < arr[i]) b = i;
    }
    int x = max(a, b) + 1, y = N - min(a, b), z = min(a, b) + 1 + N - max(a, b);
    cout << min({x, y, z}) << '\n';
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

