#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct Ball {
    int n;
    int c;
    int s;
};

bool compare(Ball &p, Ball &q) { return p.c < q.c; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Ball> input(N);
    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i) {
        input[i].n = i;
        cin >> input[i].c >> input[i].s;
    }

    sort(all(input), compare);

    for (int i = 0; i < N; ++i) cout << input[i].n << ' ' << input[i].c << ' ' << input[i].s << "\n";

    for (int i = 1; i < N; ++i) {
        if (input[i].c > input[i - 1].c) {
            if (input[i].s > input[i - 1].s) arr[input[i].n] += input[i - 1].s;
            else if (input[i - 1].s > input[i].s) arr[input[i - 1].n] += input[i].s;
        }
    }

    for (int i = 0; i < N; ++i) cout << arr[i] << "\n";

    return 0;
}
