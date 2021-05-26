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

    int N, M, arr[250000];
    ll sum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N - M + 1; ++i) {
        cout << arr[(i + M) / 2] << '\n';
        sum += arr[(i + M) / 2];
    }
    cout << sum << '\n';

    return 0;
}
