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

    int N, M, x1, x2, y1, y2; cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    int arr[101][101];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> arr[i][j];
    for (int i = y1; i <= y2; ++i) {
        for (int j = x2; j >= x1; --j)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}

