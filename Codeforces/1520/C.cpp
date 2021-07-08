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
    int N, cnt = 0;
    cin >> N;
    if (N == 2) {
        cout << "-1\n";
        return;
    }

    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j % 2 == 0)
                arr[i][j] = ++cnt;
            else
                arr[i + 1][j] = ++cnt;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0)
            arr[N - 1][i] = ++cnt;
        else
            arr[0][i] = ++cnt;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
