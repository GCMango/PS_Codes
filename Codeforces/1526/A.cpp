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
    int N, input[50];
    cin >> N;
    N *= 2;
    for (int i = 0; i < N; ++i) cin >> input[i];
    sort(input, input + N);
    for (int i = 0; i < N / 2; ++i)
        cout << input[i] << ' ' << input[N - i - 1] << ' ';
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
