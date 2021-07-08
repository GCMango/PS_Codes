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

    int N; cin >> N;
    pll arr[100000];
    ll all = 0;
    for (int i = 0; i < N; ++i) { cin >> arr[i].x >> arr[i].y; all += arr[i].x; }
    sort(arr, arr + N, [&](pll &a, pll &b) { return a.y < b.y; } );
    int cur, s = N - 1;
    ll sum = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
        cur = s;
        while (cnt < arr[i].y && cur >= i) {
            ll tmp = cnt;
            sum += 2 * min(arr[i].y - tmp, arr[cur].x);
            cnt += min(arr[i].y - tmp, arr[cur].x);
            arr[cur].x -= min(arr[i].y - tmp, arr[cur].x);
            cur--;
            if (arr[cur].x == 0 && cur == s - 1) s--;
        }
        sum += arr[i].x;
        cnt += arr[i].x;
        arr[i].x = 0;
    }
    cout << sum << '\n';

    return 0;
}

