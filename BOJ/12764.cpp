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

    struct Comp { bool operator()(pii &a, pii &b) { return a.y > b.y; } };
    int N, idx = 0, cnt[100000];
    pii arr[100000];
    priority_queue<pii, vector<pii>, Comp> pq;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        int ch;
        if (pq.empty() || pq.top().y > arr[i].x) { ch = idx; idx++; }
        else {
            ch = pq.top().x;
            pq.pop();
        }
        cnt[ch]++;
        pq.push({ch, arr[i].y});
    }
    cout << idx << '\n';
    for (int i = 0; i < idx; ++i) cout << cnt[i] << ' ';
    cout << '\n';

    return 0;
}
