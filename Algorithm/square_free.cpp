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

const ll MAX = 100000;

ll arr[MAX + 1];

void setup() {
    arr[1] = 1;
    for (ll i = 1; i <= MAX; ++i)
        for (ll j = i * 2; j <= MAX; j += i)
            arr[j] -= arr[i];
}

ll solve(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; ++i)
        cnt += arr[i] * n / (i * i);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    setup();

    return 0;
}

