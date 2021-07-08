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

    int T; cin >> T;
    while (T--) {
        int N, M;
        char arr[1 << 10][1 << 10];
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> arr[i][j];

    }

    return 0;
}
