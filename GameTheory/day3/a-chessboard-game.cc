#include <iostream>
#include <vector>
#define N 15

using namespace std;
int gnd[N+1][N+1];
bool vis[N+1][N+1];

int d_x[] = {-2, -2, 1, -1};
int d_y[] = {1, -1, -2, -2};

bool valid(int r, int c) {
    return min(r, c) > 0 && max(r, c) <= N;
}

int go(int x, int y) {
    if(vis[x][y])   return gnd[x][y];
    vis[x][y] = true;
    vector<int> temp;
    bool crap[5] = {false};
    for(int i = 0; i < 4; i++) {
        int n_x = x + d_x[i], n_y = y + d_y[i];
        if(valid(n_x, n_y)) {
            temp.push_back(go(n_x, n_y));
            crap[temp.back()] = true;
        }
    }
    for(int i = 0; i < 5; i++)
        if(!crap[i]) {
            gnd[x][y] = i;
            break;
        }
    return gnd[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!vis[i][j])
                go(i, j);
        }
    }
    int t, x, y, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int res = 0;
        while(n--) {
            cin >> x >> y;
            res ^= gnd[x][y];
        }
        cout << (res == 0 ? "Second" : "First") << '\n';
    }
    return 0;
}
