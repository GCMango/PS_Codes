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

    int N, M, arr[100001];
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        char c; cin >> c;
        arr[i] = arr[i - 1] + (int)c - 96;
    }
    while (M--) {
        int i, j; cin >> i >> j;
        cout << arr[j] - arr[i - 1] << '\n';
    }

    return 0;
}
