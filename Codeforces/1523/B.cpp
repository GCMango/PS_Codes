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

struct A {
    int a;
    int b;
    int c;
};

void solve() {
    int N, arr[1000];
    vector<A> ans;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N - 1; i += 2) {
        int j = i + 1;
        ans.push_back({1, i, j});
        ans.push_back({2, i, j});
        if (arr[i] > arr[j]) {
            ans.push_back({1, i, j});
            ans.push_back({1, i, j});
            ans.push_back({2, i, j});
            ans.push_back({1, i, j});
        }
        else {
            ans.push_back({1, i, j});
            ans.push_back({2, i, j});
            ans.push_back({1, i, j});
            ans.push_back({2, i, j});
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].a << ' ' << ans[i].b + 1 << ' ' << ans[i].c + 1 << '\n';
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

// 5 7 8 9 4 6
// 7 16
// 23 16
// 23 -30
// -7 -30
// -7 -16
// 23 16
// 23 -7
// 16 -7
// 16 -23
// -7 -23
// -7 
//
// 16 7
// 23 7
// 23 -16
// -9 -16
// -9 -7
// - 16
