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

int N;
ll mx = 0;
ll input[100001] = { (int)1e9 }, sum[100001] = { 0, }, tree[400004];

int init_tree(int start, int fin, int cur) {
    if (start == fin) return tree[cur] = start;
    int mid = (start + fin) / 2;
    int a = init_tree(start, mid, cur * 2), b = init_tree(mid + 1, fin, cur * 2 + 1);
    return tree[cur] = input[a] < input[b] ? a : b;
}

int get_min(int start, int fin, int cur, int left, int right) {
    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return tree[cur];
    int mid = (start + fin) / 2;
    int a = get_min(start, mid, cur * 2, left, right), b = get_min(mid + 1, fin, cur * 2 + 1, left, right);
    return input[a] < input[b] ? a : b;
}

void solve(int start, int fin) {
    if (start > fin) return;
    int idx = get_min(1, N, 1, start, fin);
    mx = max(mx, (sum[fin] - sum[start - 1]) * input[idx]);
    solve(start, idx - 1);
    solve(idx + 1, fin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> input[i];
        sum[i] = sum[i - 1] + input[i];
    }

    init_tree(1, N, 1);
    solve(1, N);

    cout << mx << '\n';

    return 0;
}
