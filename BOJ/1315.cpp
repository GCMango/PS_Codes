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

struct Quest {
    int a;
    int b;
    int c;
};

int N, dp[1001][1001];
Quest arr[50];

int dfs(int a, int b, bitset<50> bit) {
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    int cnt = 0, pnt = 0;
    for (int i = 0; i < N; ++i) {
        if (a >= arr[i].a || b >= arr[i].b) {
            if (!bit.test(i)) pnt += arr[i].c;
            bit.set(i, 1);
            cnt++;
        }
    }
    ret = cnt;
    for (int i = a; i <= min(1000, a + pnt); ++i)
        ret = max(ret, dfs(i, min(1000, a + b + pnt - i), bit));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i].a >> arr[i].b >> arr[i].c;
    bitset<50> bit; bit.reset();
    cout << dfs(1, 1, bit) << '\n';

    return 0;
}
