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

int N, M, arr[1000][1000];

void print_row() {
    for (int j = 0; j < M - 1; ++j) cout << 'R';
    cout << 'D';
    for (int j = 0; j < M - 1; ++j) cout << 'L';
    cout << 'D';
}

void print_col() {
    for (int j = 0; j < N - 1; ++j) cout << 'D';
    cout << 'R';
    for (int j = 0; j < N - 1; ++j) cout << 'U';
    cout << 'R';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    if (N % 2) {
        for (int i = 0; i < N / 2; ++i) print_row();
        for (int i = 0; i < M - 1; ++i) cout << 'R';
    }
    else if (M % 2) {
        for (int i = 0; i < M / 2; ++i) print_col();
        for (int i = 0; i < N - 1; ++i) cout << 'D';
    }
    else {
        int mni = 0, mnj = 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if ((i + j) % 2 && arr[i][j] < arr[mni][mnj])
                    mni = i, mnj = j;
        for (int i = 0; i < mni / 2; ++i) print_row();
        if (mnj == 0) cout << 'R';
        cout << 'D';
        for (int i = 0; i < M - 2; ++i) {
            if (i + 1 == mnj) cout << 'R';
            cout << 'R' << (i % 2 ? 'D' : 'U');
        }
        if (mnj == M - 1) cout << 'R';
        if (mni / 2 != N / 2 - 1) cout << 'D';
        for (int i = mni / 2 + 1; i < N / 2; ++i) {
            for (int j = 0; j < M - 1; ++j) cout << 'L';
            cout << 'D';
            for (int j = 0; j < M - 1; ++j) cout << 'R';
            if (i != N / 2 - 1) cout << 'D';
        }
    }
    cout << '\n';

    return 0;
}
