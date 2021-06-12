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
    int N, M, arr[1000];
    cin >> N >> M;
    vector<int> one;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        arr[i] = c - '0';
        if (arr[i])
            one.push_back(i);
    }
    for (int i = 0; i < one.size(); ++i) {
        int o = one[i], a = -1e9, b = 1e9;
        if (i > 0) a = one[i - 1];
        if (i < one.size() - 1) b = one[i + 1];
        for (int j = max({0, o - M, (o + a) / 2 + 1}); j < o; ++j)
            arr[j] = 1;
        for (int j = o + 1; j < min({N, o + M + 1, (o + b) / 2 + ((o + b) % 2 == 1)}); ++j)
            arr[j] = 1;
    }
    for (int i = 0; i < N; ++i)
        cout << arr[i];
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
