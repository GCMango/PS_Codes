#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dist(a, b) abs(a.x - b.x) + abs(a.y - b.y)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
vector<pii> input;

int solve(pii a, pii b, int cur) {
    if (cur > M) return 0;

    return min(solve(input[cur], b, cur + 1) + dist(a, input[cur]), solve(a, input[cur], cur + 1) + dist(b, input[cur]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    input.resize(M + 1);
    for (int i = 1; i <= M; ++i)
        cin >> input[i].y >> input[i].x;

    cout << solve({1, 1}, {N, N}, 1);

    return 0;
}
