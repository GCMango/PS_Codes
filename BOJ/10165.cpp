#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct Bus {
    int n;
    int start;
    int end;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<Bus> arr(M);
    for (int i = 0; i < M; ++i) {
        arr[i].n = i + 1;
        cin >> arr[i].start >> arr[i].end;
    }

    return 0;
}
