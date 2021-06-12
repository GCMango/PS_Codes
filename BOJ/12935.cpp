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

    int N;
    cin >> N;
    cout << 500 << '\n';
    for (int i = 1; i <= 500; ++i) {
        if (i * 2 <= 500)
            cout << i - 1 << ' ' << i * 2 - 1 << '\n';
        if (i * 2 + 1 <= 500)
            cout << i - 1 << ' ' << i * 2 << '\n';
    }

    return 0;
}

