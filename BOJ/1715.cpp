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

// 10 20 40
// 10 + 20 + 30 + 40 = 100
//
// 30 50 60
// 30 + 50 + 80 + 60 = 220
// 30 + 60 + 90 + 50 = 230
// 50 + 60 + 110 + 30 = 250
//
// 10 60 70
// 10 + 60 + 70 + 70 = 210
// 10 + 70 + 80 + 60 = 220
// 70 + 80 + 150 + 10 = 310
//
// 1 2 3 4
// 1 + 2 + 3 + 3 + 6 + 4 = 19
// 1 + 3 + 4 + 2 + 6 + 4 = 20
// 2 + 3 + 5 + 1 + 6 + 4 = 21
// 1 + 4 + 5 + 2 + 7 + 3 = 22

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0, m = 0;
    cin >> N;
    vector<int> input(N);

    for (int i = 0; i < N; ++i) cin >> input[i];

    sort(all(input));

    m = input[0];
    for (int i = 1; i < N; ++i) {
        sum += m + input[i];
        m += input[i];
    }

    cout << sum << '\n';

    return 0;
}
