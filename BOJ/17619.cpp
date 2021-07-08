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

    int N, Q, con[100001];
    pair<int, pii> arr[100001];
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        int y;
        cin >> arr[i].y.x >> arr[i].y.y >> y;
        arr[i].x = con[i] = i;
    }
    sort(arr + 1, arr + N + 1, [&](pair<int, pii>& a, pair<int, pii>& b) {
        if (a.y.x != b.y.x) return a.y.x < b.y.x;
        return a.y.y < b.y.y;
    });
    for (int i = 1; i <= N; ++i) {
        if (arr[i - 1].y.x <= arr[i].y.x && arr[i].y.x <= arr[i - 1].y.y) {
            con[arr[i].x] = con[arr[i - 1].x];
            arr[i].y.y = max(arr[i].y.y, arr[i - 1].y.y);
        }
    }
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << (a != b && con[a] == con[b] ? 1 : 0) << '\n';
    }

    return 0;
}
