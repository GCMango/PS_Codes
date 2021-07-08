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

    int T;
    cin >> T;
    while (T--) {
        int N, cnt = 0, arr[100001];
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> arr[i];
        for (int i = 1; i <= N; ++i)
            for (int j = arr[i] - i; j <= N; j += arr[i])
                if (i < j && 1LL * arr[i] * arr[j] == i + j) cnt++;
        cout << cnt << '\n';
    }

    return 0;
}
