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

struct INFO {
    ll x, y;
    ll p, q;
    INFO (ll xx = 0, ll yy = 0) : x(xx), y(yy), p(1), q(0) {}
};

bool comp(INFO &a, INFO &b) {
    if (a.q * b.p != a.p * b.q)
        return a.q * b.p < a.p * b.q;
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<INFO> arr;
    
    for (int i = 0; i < N; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'Y')
            arr.push_back(INFO(x, y));
    }

    sort(all(arr), comp);

    for (int i = 1; i < arr.size(); ++i)
        arr[i].p = arr[i].x - arr[0].x, arr[i].q = arr[i].y - arr[0].y;

    sort(arr.begin() + 1, arr.end(), comp);

    cout << arr.size() << '\n';
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i].x << ' ' << arr[i].y << '\n';

    return 0;
}


