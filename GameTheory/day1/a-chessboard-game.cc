#include <iostream>
#define N 15

using namespace std;
bool win[N+1][N+1];
bool vis[N+1][N+1];

int d_x[] = {-2, -2, 1, -1};
int d_y[] = {1, -1, -2, -2};

bool valid(int r, int c) {
    return min(r, c) > 0 && max(r, c) <= N;
}

bool go(int x, int y) {
    if(vis[x][y])   return win[x][y];
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int n_x = x + d_x[i], n_y = y + d_y[i];
        if(valid(n_x, n_y)) {
            win[x][y] |= !go(n_x, n_y);
        }
    }
    return win[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!vis[i][j])
                go(i, j);
        }
    }
    int t, x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << (win[x][y] ? "First" : "Second") << '\n';
    }
    return 0;
}
