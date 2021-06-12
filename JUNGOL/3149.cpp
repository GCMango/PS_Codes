#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, a, b, mn = 1e9, arr[3000];

void dfs(int cur, int cnt) {
    if (cur == M) {
        mn = min(mn, cnt);
        return;
    }
    if (cnt >= mn) return;

    int tmp = a;
    a = arr[cur];
    dfs(cur + 1, cnt + abs(tmp - arr[cur]));
    a = tmp;

    tmp = b;
    b = arr[cur];
    dfs(cur + 1, cnt + abs(tmp - arr[cur]));
    b = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> a >> b >> M;
    for (int i = 0; i < M; ++i) cin >> arr[i];
    dfs(0, 0);
    cout << mn << '\n';

    return 0;
}

