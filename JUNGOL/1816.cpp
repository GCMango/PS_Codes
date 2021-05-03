#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, S, C;
    cin >> M >> S >> C;
    vector<int> input(C);
    for (int i = 0; i < C; ++i) cin >> input[i];
    sort(input.begin(), input.end());

    int len = input[C - 1] - input[0] + 1;
    vector<int> lens;
    for (int i = 0; i < C - 1; ++i)
        lens.push_back(input[i + 1] - input[i] - 1);
    sort(lens.rbegin(), lens.rend());

    for (int i = 0; i < min(M - 1, C - 1); ++i)
        len -= lens[i];

    cout << len << "\n";

    return 0;
}
