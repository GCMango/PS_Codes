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
vector<int> input;
vector<int> tree;

int init_tree(int start, int fin, int cur) {
    if (start == fin) return tree[cur] = input[start];
    int mid = (start + fin) / 2;
    return tree[cur] = max(init_tree(start, mid, cur * 2), init_tree(mid + 1, fin, cur * 2 + 1));
}

int get_val(int start, int fin, int cur, int idx) {
    if (idx < start)
        return 0;
    if (idx >= start && input[idx] > tree[cur]) {
        return (fin - start + 1);
    }
    if (start == fin) return 0;
    int mid = (start + fin) / 2;
    return get_val(start, mid, cur * 2, idx) + get_val(mid + 1, fin, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    input.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; ++i) cin >> input[i];

    init_tree(1, N, 1);

    for (int i = 1; i <= N; ++i)
        cout << i - get_val(1, N, 1, i) << '\n';

    return 0;
}
