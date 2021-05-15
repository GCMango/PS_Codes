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

int dist(pii a, pii b) { return abs(a.x - b.x) + abs(a.y - b.y); }
bool compare(pii p, pii q) { return abs(p.x + p.y) < abs(q.x + q.y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, mn = 1e9;
    cin >> N;
    vector<pii> input(N);
    for (int i = 0; i < N; ++i)
        cin >> input[i].x >> input[i].y;

    sort(all(input), compare);

    for (int i = 1; i < N; ++i)
        mn = min(mn, dist(input[i - 1], input[i]));

    cout << mn * mn << '\n';

    return 0;
}
