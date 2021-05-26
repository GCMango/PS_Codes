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

int input[50];

void solve() {
    int N;
    bool need = false;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
        if (i > 0 && i < N - 1 && input[i] != i + 1)
            need = true;
    }
    int r = 0;
    if (input[0] != 1) r++;
    if (input[N - 1] != N) r++;
    if (input[0] == N && input[N - 1] == 1) r++;
    cout << max(r, (int)need) << '\n';
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
