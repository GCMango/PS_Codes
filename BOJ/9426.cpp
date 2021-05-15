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

int N, K, sum = 0;
int a[250000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);
    
    for (int i = K; i <= N; ++i) {
        int j = i - K;
        sum += a[j + (i - j + 1) / 2 - 1];
    }

    cout << sum << '\n';

    return 0;
}

// 0 1 2 3 4
// 1 2 3 4 5
