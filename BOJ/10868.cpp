#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M;
vector<int> input;
vector<int> tree;

int init_tree(int start, int fin, int cur) {
    if (start == fin) return tree[cur] = input[start];
    int mid = (start + fin) / 2;
    return tree[cur] = min(init_tree(start, mid, cur * 2), init_tree(mid + 1, fin, cur * 2 + 1));
}

int get_min(int start, int fin, int cur, int left, int right) {
    if (left > fin || right < start) return (int)1e9;
    if (left <= start && fin <= right) return tree[cur];
    int mid = (start + fin) / 2;
    return min(get_min(start, mid, cur * 2, left, right), get_min(mid + 1, fin, cur * 2 + 1, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    input.resize(N + 1);
    tree.resize(N * 4);
    for (int i = 1; i <= N; ++i) cin >> input[i];

    init_tree(1, N, 1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << get_min(1, N, 1, a, b) << "\n";
    }

    return 0;
}

